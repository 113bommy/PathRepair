#include <bits/stdc++.h>
using namespace std;
const int TURNS = 1605;
int n;
vector<int> pos[2];
int dp[81][81][TURNS];
int get_turns(int w, int b) {
  assert(pos[0].size() + pos[1].size() >= w + b);
  int i = pos[0].size() + pos[1].size() - w - b;
  assert(pos[1].size() >= b);
  int bp = pos[1].size() - b;
  int j = pos[1][bp];
  return abs(i - j);
}
int go(int w, int b, int turns) {
  if (w == 0 || b == 0) return 0;
  int &ans = dp[w][b][turns];
  if (ans != -1) return ans;
  ans = 0;
  for (int use = 0; use <= w; ++use) {
    int new_turns = turns - get_turns(w - use, b);
    if (new_turns >= 0) {
      ans = max(ans, use * (w - use) + go(w - use, b - 1, new_turns));
    }
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    pos[x].push_back(i);
  }
  memset(dp, 255, sizeof(dp));
  for (int i = 0; i < n * (n - 1) / 2; ++i) {
    cout << go(pos[0].size(), pos[1].size(), min(i, TURNS)) << " ";
  }
  cout << "\n";
}
