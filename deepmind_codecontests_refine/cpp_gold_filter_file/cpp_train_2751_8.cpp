#include <bits/stdc++.h>
using namespace std;
const long long mod1 = 1e9 + 7, mod2 = 998244353, K = 5e4 + 5, maxn = 5e4 + 5;
const double pi = acos(-1);
string s, res = "";
long long n, m, a[maxn], b[maxn], ans = 0;
set<pair<long long, long long> > st;
void solve() {
  cin >> s;
  n = s.length();
  for (long long i = 0; i < n; ++i) {
    if (s[i] == '?') m++;
    res += '*';
  }
  for (long long i = 1; i <= m; ++i) {
    cin >> a[i] >> b[i];
  }
  long long now = 0;
  long long sum = 0;
  for (long long i = 0; i < n; ++i) {
    if (s[i] == '(') {
      sum++;
      res[i] = s[i];
    }
    if (s[i] == ')') {
      sum--;
      res[i] = s[i];
    }
    if (s[i] == '?') {
      sum--;
      res[i] = ')';
      now++;
      st.insert(make_pair(a[now] - b[now], i));
      ans += b[now];
    }
    if (sum < 0) {
      if (st.size() == 0) {
        cout << -1;
        return;
      }
      auto it = st.begin();
      st.erase(it);
      ans += (*it).first;
      long long pos = (*it).second;
      res[pos] = '(';
      sum += 2;
    }
  }
  if (sum) {
    cout << -1;
    return;
  }
  cout << ans << '\n' << res;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
