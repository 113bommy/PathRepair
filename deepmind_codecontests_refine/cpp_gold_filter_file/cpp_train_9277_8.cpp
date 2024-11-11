#include <bits/stdc++.h>
int main() {
  int n;
  int a[105];
  int amt[105] = {};
  int diffA = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    amt[a[i]]++;
  }
  std::sort(a, a + n);
  for (int i = 1; i <= 100; i++) {
    if (amt[i] > 0) diffA++;
  }
  int bestAmt = 1;
  for (int target = 1; target <= 100; target++) {
    std::map<int, int> states;
    for (int i = n - 1; i >= 0; i--) {
      if (a[i] == target) continue;
      states[a[i]] = i + 1;
    }
    for (int count = 2; count <= amt[target]; count++) {
      std::map<int, int> nextStates;
      bool success = true;
      for (auto &it : states) {
        for (int i = it.second; i < n; i++) {
          int sum = it.first + a[i];
          if (sum == count * target) {
            success = false;
            break;
          }
          auto prev = nextStates.find(sum);
          if (prev == nextStates.end() || prev->second > i + 1) {
            nextStates[sum] = i + 1;
          }
        }
        if (!success) break;
      }
      if (!success) break;
      if (diffA == 2 && count == amt[target]) count = n;
      bestAmt = std::max(bestAmt, count);
      std::swap(states, nextStates);
    }
  }
  printf("%d\n", bestAmt);
  return 0;
}
