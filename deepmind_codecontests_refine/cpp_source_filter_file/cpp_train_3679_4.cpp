#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e3 + 100;
const int MOD = 1e9 + 7;
int n, f[MAXN], fk[MAXN];
string s[MAXN], pat;
bool mark[5];
bool check(string a, string b) {
  if (a.size() >= pat.size()) a.erase(0, (int)a.size() - (int)pat.size() + 1);
  if (b.size() >= pat.size()) {
    int temp = (int)b.size() - (int)pat.size() + 1;
    b.erase(b.size() - temp, temp);
  }
  a += b;
  if (a.size() < pat.size()) return false;
  int k = 0;
  for (int i = 1; i < pat.size(); i++) {
    while (k && pat[i] != pat[k]) k = fk[k];
    if (pat[i] == pat[k]) k++;
    fk[i + 1] = k;
  }
  k = 0;
  for (int i = 0; i < a.size(); i++) {
    while (k && pat[k] != a[i]) k = fk[k];
    if (pat[k] == a[i]) k++;
    if (k == pat.size()) return true;
  }
  return false;
}
int get(int ind) {
  int rem = n - ind + 1;
  return f[rem];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  s[0] = "a";
  s[1] = "b";
  for (int i = 2; i < MAXN; i++) {
    s[i] = s[i - 1] + s[i - 2];
    if (s[i].size() > 2 * MAXN) s[i].erase(MAXN, (int)s[i].size() - 2 * MAXN);
  }
  f[0] = 0;
  f[1] = 1;
  for (int i = 2; i < MAXN; i++) f[i] = (f[i - 1] + f[i - 2]) % MOD;
  int q;
  cin >> n >> q;
  n--;
  while (q--) {
    cin >> pat;
    if (pat == "b")
      cout << f[n] << endl;
    else if (pat == "a")
      cout << (n == 1 ? 1 : f[n - 1]) << endl;
    else {
      long long ans = 0;
      for (int i = 2; i < min(n + 1, 23); i++)
        if (check(s[i - 1], s[i - 2])) ans = (ans + get(i)) % MOD;
      mark[0] = mark[1];
      for (int i = 23; i < 25 && i <= n; i++)
        if (check(s[i - 1], s[i - 2])) mark[i & 1] = 1;
      for (int i = 23; i <= n; i++)
        if (mark[i & 1]) ans = (ans + get(i)) % MOD;
      cout << ans << endl;
    }
  }
  return 0;
}
