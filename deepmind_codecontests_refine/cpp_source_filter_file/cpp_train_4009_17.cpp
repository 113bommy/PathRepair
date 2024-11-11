#include <bits/stdc++.h>
using namespace std;
const int len = 1 << 16;
string str;
int n, tot;
int son[555][2], fa[555], val[555];
int must[555];
long long int a[55], b[55], f[255][len], tmp1[len], tmp2[len];
inline void FWTAnd(long long int* A, long long int* B, int n) {
  for (int len = 2; len <= n; len <<= 1)
    for (int i = 0; i < n / len; ++i)
      for (int j = 0; j < len / 2; ++j)
        A[i * len + j] =
            (A[i * len + j] + A[i * len + j + len / 2]) % 1000000007;
  for (int len = 2; len <= n; len <<= 1)
    for (int i = 0; i < n / len; ++i)
      for (int j = 0; j < len / 2; ++j)
        B[i * len + j] =
            (B[i * len + j] + B[i * len + j + len / 2]) % 1000000007;
  for (int i = 0; i < n; ++i) A[i] = A[i] * B[i] % 1000000007;
  for (int len = 2; len <= n; len <<= 1)
    for (int i = 0; i < n / len; ++i)
      for (int j = 0; j < len / 2; ++j)
        A[i * len + j] =
            (A[i * len + j] - A[i * len + j + len / 2] + 1000000007) %
            1000000007;
}
inline void FWTOr(long long int* A, long long int* B, int n) {
  for (int len = 2; len <= n; len <<= 1)
    for (int i = 0; i < n / len; ++i)
      for (int j = 0; j < len / 2; ++j)
        A[i * len + j + len / 2] =
            (A[i * len + j] + A[i * len + j + len / 2]) % 1000000007;
  for (int len = 2; len <= n; len <<= 1)
    for (int i = 0; i < n / len; ++i)
      for (int j = 0; j < len / 2; ++j)
        B[i * len + j + len / 2] =
            (B[i * len + j] + B[i * len + j + len / 2]) % 1000000007;
  for (int i = 0; i < n; ++i) A[i] = A[i] * B[i] % 1000000007;
  for (int len = 2; len <= n; len <<= 1)
    for (int i = 0; i < n / len; ++i)
      for (int j = 0; j < len / 2; ++j)
        A[i * len + j + len / 2] =
            (A[i * len + j + len / 2] - A[i * len + j] + 1000000007) %
            1000000007;
}
inline int get(int A, int B, int C, int D) {
  return (1 << (A << 0)) + (1 << (B << 1)) + (1 << (C << 2)) + (1 << (D << 3));
}
int main() {
  ios::sync_with_stdio(false);
  cin >> str >> n;
  int pos = 1;
  tot = 1;
  for (int s = 0; s < str.size(); ++s) {
    if (str[s] == '(') {
      if (!son[pos][0])
        son[pos][0] = ++tot;
      else
        son[pos][1] = ++tot;
      fa[tot] = pos;
      pos = tot;
    } else if (str[s] == ')') {
      pos = fa[pos];
      if (!son[pos][1]) continue;
      if (val[pos] == 1) {
        for (int i = 0; i < len; ++i) f[pos][i] = f[son[pos][0]][i];
        FWTAnd(f[pos], f[son[pos][1]], len);
      } else if (val[pos] == 2) {
        for (int i = 0; i < len; ++i) f[pos][i] = f[son[pos][0]][i];
        FWTOr(f[pos], f[son[pos][1]], len);
      } else {
        for (int i = 0; i < len; ++i)
          tmp1[i] = f[son[pos][0]][i], tmp2[i] = f[son[pos][1]][i];
        FWTAnd(tmp1, tmp2, len);
        for (int i = 0; i < len; ++i) f[pos][i] = tmp1[i];
        for (int i = 0; i < len; ++i)
          tmp1[i] = f[son[pos][0]][i], tmp2[i] = f[son[pos][1]][i];
        FWTOr(tmp1, tmp2, len);
        for (int i = 0; i < len; ++i)
          f[pos][i] = (f[pos][i] + tmp1[i]) % 1000000007;
      }
    } else if ('A' <= str[s] && str[s] <= 'D') {
      int d = 1 << (str[s] - 'A'), S = 0;
      for (int i = 0; i < 16; ++i)
        if (i & d) S |= 1 << i;
      f[pos][S] = 1;
    } else if ('a' <= str[s] && str[s] <= 'd') {
      int d = 1 << (str[s] - 'a'), S = 0;
      for (int i = 0; i < 16; ++i)
        if ((~i) & d) S |= 1 << i;
      f[pos][S] = 1;
    } else if (str[s] == '?' && str[s + 1] != '(') {
      for (int i = 0; i < 4; ++i) {
        int d = 1 << i, S = 0;
        for (int i = 0; i < 16; ++i)
          if (i & d) S |= 1 << i;
        f[pos][S] = 1;
      }
      for (int i = 0; i < 4; ++i) {
        int d = 1 << i, S = 0;
        for (int i = 0; i < 16; ++i)
          if ((~i) & d) S |= 1 << i;
        f[pos][S] = 1;
      }
    } else if (str[s] == '&')
      val[pos] = 1;
    else if (str[s] == '|')
      val[pos] = 2;
  }
  for (int i = 0; i < 16; ++i) must[i] = -1;
  for (int i = 1; i <= n; ++i) {
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    must[a + b * 2 + c * 4 * d + 8] = e;
  }
  long long int ans = 0;
  for (int S = 0; S < len; ++S) {
    for (int i = 0; i < 16; ++i)
      if (must[i] != -1 && ((S & (1 << i)) > 0) != must[i]) goto end;
    ans = (ans + f[1][S]) % 1000000007;
  end:;
  }
  cout << ans << endl;
  return 0;
}
