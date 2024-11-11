#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> alarms;
  for (int i = 0; i < n; ++i) {
    int v;
    cin >> v;
    alarms.push_back(v);
  }
  sort(alarms.begin(), alarms.end());
  int start = 0;
  int end = 0;
  int result = 0;
  int num_alarms_in_window = 0;
  vector<int> can_be_erased;
  for (int w = m; w <= 1000001; ++w) {
    for (; start < alarms.size(); ++start) {
      if (alarms[start] == -1) {
        continue;
      } else if (alarms[start] >= w - m) {
        break;
      }
      num_alarms_in_window--;
    }
    for (; end < alarms.size(); ++end) {
      if (alarms[end] >= w) break;
      num_alarms_in_window++;
      can_be_erased.push_back(end);
    }
    while (num_alarms_in_window >= k) {
      alarms[can_be_erased.back()] = -1;
      can_be_erased.pop_back();
      --num_alarms_in_window;
      ++result;
    }
  }
  printf("%d\n", result);
  return 0;
}
