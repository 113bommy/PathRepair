#include <bits/stdc++.h>
using namespace std;
const long long base = 131, mod1 = 20170331, mod2 = 201721039;
const int maxn = 1000100, maxm = 220;
long long ha1[maxn], ha2[maxn], Ha1[maxm], Ha2[maxm];
string p, s, ans;
int k, ls, lp;
bool q[maxm];
bool check(int l) {
  for (int i = ls - 1; i >= 0; i--) {
    Ha1[i] = ((i + l >= ls ? 0 : Ha1[i + l]) * base % mod1 + s[i]) % mod1;
    Ha2[i] = ((i + l >= ls ? 0 : Ha2[i + l]) * base % mod2 + s[i]) % mod2;
  }
  int now = l;
  for (int i = k - 1; i >= 0; i--) {
    if (now != 0 && ha1[i] == Ha1[now - 1] && ha2[i] == Ha2[now - 1]) {
      q[i] = 1;
      now--;
    } else
      q[i] = 0;
  }
  return now == 0;
}
int main() {
  std::ios::sync_with_stdio(false);
  getline(cin, p);
  getline(cin, s);
  cin >> k;
  lp = p.size();
  ls = s.size();
  for (int i = lp - 1; i >= 0; i--) {
    ha1[i] = ((i + k >= lp ? 0 : ha1[i + k]) * base + p[i]) % mod1;
    ha2[i] = ((i + k >= lp ? 0 : ha2[i + k]) * base + p[i]) % mod2;
  }
  ans = "";
  for (int i = 1; i <= k + 1; i++) ans += '1';
  string oo = ans;
  for (int l = 0; l <= k; l++) {
    if (lp / k * l + max(0, l - (k - lp % k)) > ls) continue;
    if (lp / k * l + min(l, lp % k) < ls) continue;
    if (!check(l)) continue;
    string now = "";
    for (int j = 0; j < k; j++) now += (char)('0' + q[j]);
    ans = min(ans, now);
  }
  if (ans != oo)
    cout << ans << endl;
  else
    cout << 0 << endl;
  return 0;
}
