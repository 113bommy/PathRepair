#include <bits/stdc++.h>
using namespace std;
long long dp[(1 << 20) + 5];
struct friends {
  int cost, maxv, mask;
  bool operator<(const friends& f) const { return maxv < f.maxv; }
};
int main() {
  srand((unsigned int)time(NULL));
  fill(dp, dp + (1 << 20) + 5, 9e18);
  dp[0] = 0;
  int n, m, c;
  cin >> n >> m >> c;
  vector<friends> vec;
  for (int i = 0; i < n; i++) {
    int cost, nes, sol;
    cin >> cost >> nes >> sol;
    int mask = 0;
    for (int i = 0; i < sol; i++) {
      int f;
      cin >> f;
      mask |= (1 << (f - 1));
    }
    vec.push_back((friends){cost, nes, mask});
  }
  sort(vec.begin(), vec.end());
  long long res = 9e18;
  for (int i = 0; i < vec.size(); i++) {
    for (int j = 0; j < 1 << m; j++) {
      if (dp[j] == 9e18) continue;
      dp[j | vec[i].mask] = min(dp[j | vec[i].mask], dp[j] + vec[i].cost);
    }
    res = min(res, dp[(1 << m) - 1] + 1LL * c * vec[i].maxv);
  }
  cout << (res == 9e18 ? -1 : res) << endl;
}
