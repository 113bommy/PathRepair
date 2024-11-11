#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > t[1010];
int n, x, y, cn;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  cn = n;
  while (n--) {
    cin >> x >> y;
    t[y / 1000].push_back({x, cn - n});
  }
  for (int i = 0; i < 1001; i++) {
    if (i % 2)
      sort(t[i].rbegin(), t[i].rend());
    else
      sort(t[i].begin(), t[i].end());
    for (int j = 0; j < t[i].size(); j++) {
      cout << t[i][j].second << " ";
    }
  }
  cout << "\n";
  return 0;
}
