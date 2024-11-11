#include <bits/stdc++.h>
using namespace std;
const int LIM = 300;
const int DIV_CNT = 10;
const int MAX_MASK = 1 << 9;
int num[LIM], cost[LIM];
int masks[LIM];
int ans = -1;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> num[i];
  for (int i = 0; i < n; ++i) cin >> cost[i];
  for (int i = 0; i < n; ++i) {
    vector<int> div;
    for (int j = 2; j * j < num[i]; ++j)
      if (num[i] % j == 0) {
        div.push_back(j);
        while (num[i] % j == 0) num[i] /= j;
      }
    if (num[i] > 1) div.push_back(num[i]);
    for (int j = i + 1; j < n; ++j) {
      masks[j] = 0;
      for (int k = 0; k < (int)div.size(); ++k)
        if (num[j] % div[k] == 0) masks[j] |= (1 << k);
    }
    vector<int> state((1 << DIV_CNT), -1);
    state[((1 << div.size()) - 1)] = cost[i];
    for (int j = i + 1; j < n; ++j) {
      for (int k = 0; k < (int)state.size(); ++k) {
        if (state[k] == -1) continue;
        int new_cost = state[k] + cost[j];
        if (state[k & masks[j]] == -1 || state[k & masks[j]] > new_cost)
          state[k & masks[j]] = new_cost;
      }
    }
    if (state[0] != -1) {
      if (ans == -1)
        ans = state[0];
      else
        ans = min(ans, state[0]);
    }
  }
  cout << ans;
  return 0;
}
