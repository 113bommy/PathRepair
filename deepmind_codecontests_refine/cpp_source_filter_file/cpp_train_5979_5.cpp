#include <bits/stdc++.h>
using namespace std;
int n, m;
pair<pair<long long, long long>, int> v1[50050];
pair<pair<long long, long long>, int> v2[50050];
int solve() {
  int ans = 0;
  for (int i = 0; i < (n); ++i) {
    int x1 = v1[i].first.first;
    int y1 = v1[i].first.second;
    int y2 = y1 + v1[i].second;
    for (int j = 0; j < (m); ++j) {
      int x3 = v2[j].first.first;
      int y3 = v2[j].first.second;
      int x4 = x3 + v2[i].second;
      if (x1 > x3 && x1 < x4 && y3 > y1 && y3 < y2) {
        int aux = 0x3f3f3f3f;
        aux = min(aux, abs(x3 - x1));
        aux = min(aux, abs(x4 - x1));
        aux = min(aux, abs(y1 - y3));
        aux = min(aux, abs(y2 - y3));
        ans = max(ans, aux);
      }
    }
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  while (cin >> n >> m) {
    for (int i = 0; i < (n); ++i)
      cin >> v1[i].first.first >> v1[i].first.second >> v1[i].second;
    for (int i = 0; i < (m); ++i)
      cin >> v2[i].first.first >> v2[i].first.second >> v2[i].second;
    cout << solve() << "\n";
  }
  return 0;
}
