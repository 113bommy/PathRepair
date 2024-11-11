#include <bits/stdc++.h>
using namespace std;
vector<pair<pair<int, int>, int> > v;
vector<pair<int, int> > v1;
int occ[1001];
int main() {
  ifstream in("input.txt");
  int n;
  cin >> n;
  int x, y, z;
  for (int i = 1; i <= n; i++) {
    cin >> x >> y;
    v.push_back(make_pair(make_pair(y, x), i));
  }
  sort(v.begin(), v.end());
  int k, t;
  cin >> k;
  for (int i = 1; i <= k; i++) cin >> t, v1.push_back(make_pair(t, i));
  sort(v1.begin(), v1.end());
  int total = 0;
  for (int i = n - 1; i >= 0; i--) {
    int req = v[i].first.second;
    for (int j = 0; j < k; j++) {
      if (v1[j].first >= req && v1[j].second > 0) {
        v1[j].second *= -1, occ[v[i].second] = -v1[j].second,
                            total += v[i].first.first;
        break;
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
    if (occ[i]) ans++;
  cout << ans << " " << total << endl;
  for (int i = 1; i <= n; i++)
    if (occ[i]) cout << i << " " << occ[i] << endl;
}
