#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

int main() {
  int H, W, N;
  cin >> H >> W >> N;
  map<P, int> mp;
  vector<vector<int>> g(H + 1);
  for (int i = 0; i < N; i++) {
    int X, Y;
    cin >> X >> Y, X--, Y--;
    g[X].push_back(Y);
    mp[{X, Y}] = 1;
  }
  for (int x = 0; x <= H; x++) {
    mp[{x, W}] = 1;
  }
  for (int y = 0; y <= W; y++) {
    mp[{H, y}] = 1;
  }

  int ans = 1;
  int y = 0;
  for (int x = 1; x <= H; x++) {
    int cnt = 0;
    for (auto v : g[x]) {
      if (v < y) cnt++;
    }
    if (cnt > 0 || mp[{x, y}]) break;
    if (!mp[{x, y + 1}]) y++;
    ans++;
  }

  cout << ans << endl;
}
