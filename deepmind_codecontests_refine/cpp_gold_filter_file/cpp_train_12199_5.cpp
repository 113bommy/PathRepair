#include <bits/stdc++.h>
using namespace std;
const int inf_int = 1 << 30;
const long long inf_longlong = 1LL << 62;
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;
string s, t;
pair<int, int> P[N];
void read_input() { cin >> s >> t; }
void solve() {
  int n = (int)s.size(), m = (int)t.size();
  int inx = 0;
  for (int i = 0; i < n && inx < m; i++) {
    if (s[i] == t[inx]) P[inx].first = i, inx++;
  }
  inx = m - 1;
  for (int i = n - 1; i >= 0 && inx >= 0; i--) {
    if (s[i] == t[inx]) P[inx].second = i, inx--;
  }
  int ans = max(P[0].second, n - P[m - 1].first - 1);
  for (int i = 1; i < m; i++) {
    ans = max(ans, P[i].second - P[i - 1].first - 1);
  }
  cout << ans << '\n';
}
void write_output() {}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int test_cases = 1;
  while (test_cases--) {
    read_input(), solve(), write_output();
  }
  return 0;
}
