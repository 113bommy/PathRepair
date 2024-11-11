#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
int fact[N];
char s[N];
int fres = 1;
int a, b, c, d, e, f, n;
int cur1[N], cur2[N];
int val[2][N];
inline int fastpower(int num, int po) {
  fres = 1;
  while (po > 0) {
    if (po & 1) fres = (long long)fres * num % 998244353;
    num = (long long)num * num % 998244353;
    po >>= 1;
  }
  return fres;
}
inline int nck(int n, int k) {
  if (k > n || k < 0) return 0;
  return (long long)fact[n] *
         fastpower((long long)fact[k] * fact[n - k] % 998244353,
                   998244353 - 2) %
         998244353;
}
int tmp1, tmp2, tmp3;
inline void make(bool b, int num) {
  for (int i = 0; i <= num; i++) {
    val[b][i + 1] = val[b][i] + nck(num, i);
    if (val[b][i + 1] >= 998244353) val[b][i] -= 998244353;
  }
}
inline int getsum(bool b, int l, int r) {
  if (l > r) return 0;
  tmp2 = val[b][r + 1] - val[b][l];
  if (tmp2 < 0) tmp2 += 998244353;
  return tmp2;
}
int main() {
  fact[0] = 1;
  for (int i = 1; i < N; i++) fact[i] = (long long)fact[i - 1] * i % 998244353;
  scanf("%s", s);
  n = strlen(s);
  for (int i = 0; i < n; i++) {
    if (s[i] == '(')
      a++;
    else if (s[i] == ')')
      b++;
    else
      c++;
  }
  int num = c;
  make(0, num);
  make(1, num - 1);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '(')
      a--, d++;
    else if (s[i] == ')')
      b--, e++;
    else
      c--, f++;
    if (s[i] == ')') continue;
    if (s[i] == '?') d++, f--;
    tmp1 = (d + f - b);
    if (f + c == num - 1)
      ans += getsum(1, max(0, tmp1), num - 1);
    else
      ans += getsum(0, max(0, tmp1), num);
    if (ans >= 998244353) ans -= 998244353;
    if (s[i] == '?') d--, f++;
  }
  cout << ans << endl;
  return 0;
}
