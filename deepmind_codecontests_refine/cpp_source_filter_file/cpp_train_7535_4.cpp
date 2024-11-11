#include <bits/stdc++.h>
using namespace std;
const int N = 2020, M = 12, base = 2003, MOD = 1000 * 1000 * 1000 + 7;
int sum(int a, int b) {
  a += b;
  if (a < 0)
    a += MOD;
  else if (a >= MOD)
    a -= MOD;
  return a;
}
int mul(int a, int b) { return 1LL * a * b % MOD; }
int n, m, ans, low[N], hi[N];
string s, t[M];
unordered_map<int, bool> done;
unordered_map<int, int> cnt[M];
bool check(int val) {
  if (done[val]) return false;
  done[val] = true;
  for (int i = 0; i < m; i++)
    if (cnt[i][val] < low[i] || hi[i] < cnt[i][val]) return false;
  return true;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  cin >> s >> m;
  n = s.length();
  for (int i = 0; i < m; i++) {
    cin >> t[i] >> low[i] >> hi[i];
    for (int l = 0; l < t[i].length(); l++) {
      int val = 0;
      for (int r = l; r < t[i].length(); r++) {
        val = sum(mul(val, base), t[i][r]);
        cnt[i][val]++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    int val = 0;
    for (int j = i; j < n; j++) {
      val = sum(mul(val, base), s[j]);
      ans += check(val);
    }
  }
  cout << ans;
  return 0;
}
