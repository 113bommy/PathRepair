#include <bits/stdc++.h>
using namespace std;
int n, m;
int L = 2, R = 1, cnt = 1;
vector<pair<pair<int, int>, int>> edge;
vector<pair<int, int>> ans(1000001);
map<pair<int, int>, int> num;
void NextEdge() {
  if (R == 1) {
    ++L;
    R = L - 1;
  } else {
    --R;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int X, Y;
    cin >> X >> Y;
    edge.push_back({{X, -Y}, i});
  }
  sort(edge.begin(), edge.end());
  for (int i = 0; i < m; ++i) {
    if (edge[i].first.second == -1) {
      ans[edge[i].second] = {0, cnt};
      ++cnt;
    } else {
      if (L >= cnt) {
        cout << -1 << endl;
        return 0;
      }
      ans[edge[i].second] = {L, R};
      NextEdge();
    }
  }
  for (int i = 0; i < m; ++i) {
    cout << ans[i].second + 1 << ' ' << ans[i].first + 1 << endl;
  }
}
