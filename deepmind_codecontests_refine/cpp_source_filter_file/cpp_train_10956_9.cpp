#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using pii = pair<int, int>;
string answer;
ll desc(vll& v, ll n, ll m) {
  int l = -1, r = v.size(), mid;
  while (r - l > 1) {
    mid = (l + r) / 2;
    if (v[mid] <= n)
      l = mid;
    else
      r = mid;
  }
  return 2 * (n - l) + v.size() - (1ll << m);
}
void solve() {
  int n, m;
  cin >> n >> m;
  vll v;
  string s;
  for (int i = 0; i < n; ++i) {
    cin >> s;
    v.push_back(stoll(s, 0, 2));
  }
  sort(v.begin(), v.end());
  ll l = -1ll, r = 1ll << m;
  while (true) {
    ll mid = (l + r) / 2;
    ll temp = desc(v, mid, m);
    if (temp < 0ll)
      l = mid;
    else if (temp > 1ll)
      r = mid;
    else {
      while (find(v.begin(), v.end(), mid) != v.end()) mid--;
      answer.clear();
      answer.resize(m, '0');
      for (int i = 0; i < m; ++i)
        if ((1 << i) & mid) answer[(m - 1) - i] = '1';
      break;
    }
  }
  cout << answer << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) solve();
}
