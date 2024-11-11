#include <bits/stdc++.h>
using namespace std;
int n, m;
string s;
bool bl[1010000];
int x[1010000];
int B[1010000];
long long ans = 1;
long long const mod = 1e9 + 7;
long long MI[2][1010000];
long long const mod1 = 199997, mod2 = 17777797;
int inline read() {
  int f = 0;
  char ch = getchar();
  while (ch > '9' || ch < '0') ch = getchar();
  while (ch >= '0' && ch <= '9')
    f = (f << 3) + (f << 1) + ch - '0', ch = getchar();
  return f;
}
int main() {
  cin >> n >> m;
  cin >> s;
  if (m == 0) {
    for (int i = 1; i <= n; ++i) ans *= 26, ans %= mod;
    cout << ans << "\n";
    exit(0);
  }
  int l = s.size();
  s = "0" + s;
  MI[0][0] = 1;
  MI[1][0] = 1;
  for (int i = 1; i <= n; ++i)
    MI[0][i] = MI[0][i - 1] * 26 % mod1, MI[1][i] = MI[1][i - 1] * 26 % mod2;
  long long s1 = 0, s2 = 0;
  long long str1 = 0, str2 = 0;
  for (int i = 1; i <= l; ++i) {
    s1 *= 26;
    s1 += s[i] - 'a';
    s1 %= mod1;
    s2 *= 26;
    s2 += s[i] - 'a';
    s2 %= mod2;
    str1 += (s[l - i + 1] - 'a') * MI[0][i - 1];
    str1 %= mod1;
    str2 += (s[l - i + 1] - 'a') * MI[1][i - 1];
    str2 %= mod2;
    if (s1 == str1 && s2 == str2) bl[i] = 1;
  }
  for (int i = 0; i != m; ++i) x[i] = read();
  for (int i = 1; i != m; ++i) {
    int pre = x[i - 1] + l - 1;
    if (pre < x[i]) continue;
    int len = pre - x[i] + 1;
    if (!bl[len]) cout << 0 << "\n", exit(0);
  }
  int p = 1;
  for (int i = 0; i != m; ++i) {
    int st = x[i], ed = x[i] + l - 1;
    if (p < st) p = st;
    for (p; p <= ed; ++p) B[p] = 1;
  }
  for (int i = 1; i <= n; ++i)
    if (!B[i]) ans *= 26, ans %= mod;
  cout << ans << "\n";
  return 0;
}
