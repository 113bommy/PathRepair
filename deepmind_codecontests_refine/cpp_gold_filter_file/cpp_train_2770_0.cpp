#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 3e5 + 100;
long long md = 1000000007;
void solve() {
  int n, k, m, a;
  cin >> n >> k >> m >> a;
  vector<int> s(n), last(n, 101);
  for (int i = 0; (i) < a; ++(i)) {
    int f;
    cin >> f;
    f--;
    s[f]++;
    last[f] = i;
  }
  int f = 0;
  for (int i = 0; (i) < n; ++(i))
    if (s[i]) f++;
  k = min(f + m - a, k);
  for (int i = 0; (i) < n; ++(i)) {
    int t = k;
    int t2 = k;
    vector<int> d;
    for (int j = 0; (j) < n; ++(j)) {
      if (i == j) continue;
      if (m - a == 0) {
        if (s[j] > s[i]) t2--;
        if (s[j] == s[i] && last[j] < last[i]) t2--;
      } else if (s[j] >= s[i] + m - a)
        t2--;
      if (s[j] > s[i])
        t--;
      else if (s[j] == s[i] && last[j] < last[i])
        t--;
      else {
        d.push_back(s[j]);
      }
    }
    if (t2 <= 0) {
      cout << "3 ";
      continue;
    }
    sort((d).rbegin(), (d).rend());
    int am = m - a;
    for (auto &x : d) {
      int w = s[i] + 1 - x;
      if (w > am) break;
      am -= w;
      t--;
    }
    if (t > 0 && s[i])
      cout << "1 ";
    else
      cout << "2 ";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tests = 1;
  for (int _ = 0; (_) < tests; ++(_)) {
    solve();
  }
  return 0;
}
