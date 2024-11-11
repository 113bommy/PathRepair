#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > clouds[2];
int result_Bin(int x, int len, int w, int s) {
  int midx = INT_MAX, mid, l = 0, h = clouds[1].size() - 1,
      which = 1 - 2 * (s >= 0);
  while (l <= h) {
    mid = (l + h) / 2;
    if ((clouds[1][mid].first + len) * (long long)(w - which) >
        s * (long long)(w + which)) {
      h = mid - 1;
      midx = min(midx, mid);
    } else
      l = mid + 1;
  }
  return (midx == INT_MAX) ? 0 : clouds[1][midx].second;
}
int main() {
  int n, l, w;
  cin >> n >> l >> w;
  for (int i = 0; i < n; i++) {
    int s, v;
    cin >> s >> v;
    clouds[v < 0].push_back(make_pair(s, 0));
  }
  for (int i = 0; i < 2; i++) {
    sort(clouds[i].begin(), clouds[i].end());
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < clouds[i].size(); j++) {
      clouds[i][j].second = clouds[i].size() - j;
    }
  }
  long long ans = 0;
  for (int i = 0; i < clouds[0].size(); i++) {
    int s = clouds[0][i].first, eL;
    ans += result_Bin(eL, l, w, s);
  }
  cout << ans << endl;
  return 0;
}
