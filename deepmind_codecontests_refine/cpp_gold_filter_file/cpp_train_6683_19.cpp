#include <bits/stdc++.h>
using namespace std;
const int Z = (int)5e3 + 228;
const int N = (int)3e5 + 228;
const int INF = (int)1e9 + 228;
const int MOD = (int)1e9 + 7;
const long long LLINF = (long long)1e18 + 228;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  long long k;
  cin >> n >> k;
  vector<int> a;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a.push_back(x);
  }
  sort(a.begin(), a.end());
  vector<pair<long long, long long> > v;
  for (int i = 0; i < n; i++)
    if (v.empty() || a[i] != v.back().first)
      v.push_back({a[i], 1});
    else
      v.back().second++;
  long long l = 0, r = v.size() - 1, cntL = 0, cntR = 0;
  while (l < r) {
    if (cntL + v[l].second <= cntR + v[r].second) {
      if ((v[l + 1].first - v[l].first) * (cntL + v[l].second) <= k) {
        cntL += v[l].second;
        k -= (v[l + 1].first - v[l].first) * cntL;
        l++;
      } else {
        cntL += v[l].second;
        cout << v[r].first - (v[l].first + (k / cntL));
        return 0;
      }
    } else {
      if ((v[r].first - v[r - 1].first) * (cntR + v[r].second) <= k) {
        cntR += v[r].second;
        k -= (v[r].first - v[r - 1].first) * cntR;
        r--;
      } else {
        cntR += v[r].second;
        cout << v[r].first - (k / cntR) - v[l].first;
        return 0;
      }
    }
  }
  cout << 0;
  return 0;
}
