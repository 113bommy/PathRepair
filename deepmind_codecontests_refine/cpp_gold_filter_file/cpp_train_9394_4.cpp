#include <bits/stdc++.h>
long long gi() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) f ^= ch == '-', ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return f ? x : -x;
}
std::mt19937 rnd(time(NULL));
template <class T>
void cxk(T& a, T b) {
  a = a > b ? a : b;
}
template <class T>
void cnk(T& a, T b) {
  a = a < b ? a : b;
}
std::bitset<2001> s[2001];
int n, m, o;
struct mat {
  bool s[2][2];
  mat() { memset(s, 0, sizeof s); }
  bool* operator[](int x) { return s[x]; }
};
mat operator*(mat a, mat b) {
  mat c;
  for (int j = 0; j < 2; ++j)
    for (int i = 0; i < 2; ++i)
      for (int k = 0; k < 2; ++k) c[i][k] ^= a[i][j] & b[j][k];
  return c;
}
bool ans[2010];
int pos[2010];
mat coef[1010];
int main() {
  n = gi(), m = gi();
  char op[11];
  for (int i = 1; i <= n; ++i) coef[i][0][0] = coef[i][1][1] = 1;
  while (m--) {
    scanf("%s", op);
    static int c, a[1010];
    c = gi();
    for (int j = 1; j <= c; ++j) a[j] = gi();
    if (op[0] == 'm') {
      char ch = getchar();
      ++o;
      for (int j = 1; j <= c; ++j)
        s[o][a[j]] = coef[a[j]][0][0], s[o][a[j] + n] = coef[a[j]][0][1];
      s[o][0] = ch == 'R' || ch == 'B';
      ++o;
      for (int j = 1; j <= c; ++j)
        s[o][a[j]] = coef[a[j]][1][0], s[o][a[j] + n] = coef[a[j]][1][1];
      s[o][0] = ch == 'Y' || ch == 'B';
    } else if (op[0] == 'R' && op[1] == 'Y') {
      mat t;
      t[0][1] = t[1][0] = 1;
      for (int i = 1; i <= c; ++i) coef[a[i]] = t * coef[a[i]];
    } else if (op[0] == 'R' && op[1] == 'B') {
      mat t;
      t[0][0] = t[1][1] = t[1][0] = 1;
      for (int i = 1; i <= c; ++i) coef[a[i]] = t * coef[a[i]];
    } else if (op[0] == 'Y') {
      mat t;
      t[1][1] = t[0][1] = t[0][0] = 1;
      for (int i = 1; i <= c; ++i) coef[a[i]] = t * coef[a[i]];
    }
  }
  n <<= 1;
  for (int i = 1, p = 1; p <= n && i <= o; ++i) {
    for (int j = i; j <= o; ++j)
      if (s[j][p]) {
        std::swap(s[j], s[i]);
        break;
      }
    if (!s[i][p]) {
      --i;
      ++p;
      continue;
    }
    for (int j = i + 1; j <= o; ++j)
      if (s[j][p]) s[j] ^= s[i];
    pos[i] = p++;
  }
  for (int i = o; i; --i) {
    bool w = s[i][0];
    for (int j = i + 1; j <= o; ++j)
      if (s[i][pos[j]]) w ^= ans[pos[j]];
    if (pos[i])
      ans[pos[i]] = w;
    else if (w)
      puts("NO"), exit(0);
  }
  n >>= 1;
  puts("YES");
  for (int i = 1; i <= n; ++i)
    if (ans[i])
      putchar(ans[i + n] ? 'B' : 'R');
    else
      putchar(ans[i + n] ? 'Y' : '.');
  return 0;
}
