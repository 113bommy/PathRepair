#include <bits/stdc++.h>
using namespace std;
const int N = 5000;
const int INF = 1e9;
int min_cost[N / 2 + 5][N + 5][2];
int n;
int height[N + 5];
int get_cost(int type, int idx) {
  if (type == 0) {
    return max(0, height[idx - 1] - height[idx] + 1) +
           max(0, height[idx + 1] - height[idx] + 1);
  } else {
    return max(0, min(height[idx - 2] - 1, height[idx - 1]) - height[idx] + 1) +
           max(0, height[idx + 1] - height[idx] + 1);
  }
}
void gen_min_cost() {
  for (int idx = 0; idx <= n; idx++) {
    min_cost[0][idx][0] = 0;
    min_cost[0][idx][1] = INF;
  }
  for (int house = 1; house <= (n + 1) / 2; house++) {
    min_cost[house][0][0] = min_cost[house][0][1] = INF;
  }
  for (int house = 1; house <= (n + 1) / 2; house++) {
    for (int idx = 1; idx <= n; idx++) {
      min_cost[house][idx][0] =
          min(min_cost[house][idx - 1][0], min_cost[house][idx - 1][1]);
      if (house == 1) {
        min_cost[house][idx][1] = get_cost(0, idx);
      } else if (idx > 2) {
        min_cost[house][idx][1] =
            min(min_cost[house - 1][idx - 2][0] + get_cost(0, idx),
                min_cost[house - 1][idx - 2][1] + get_cost(1, idx));
      } else {
        min_cost[house][idx][1] = INF;
      }
      for (int i = 0; i < 2; i++)
        min_cost[house][idx][i] = min(min_cost[house][idx][i], INF);
    }
  }
}
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> height[i];
  height[0] = height[n + 1] = -INF;
  gen_min_cost();
  for (int house = 1; house <= (n + 1) / 2; house++) {
    if (house > 1) cout << " ";
    cout << min(min_cost[house][n][0], min_cost[house][n][1]);
  }
  cout << endl;
  return 0;
}
