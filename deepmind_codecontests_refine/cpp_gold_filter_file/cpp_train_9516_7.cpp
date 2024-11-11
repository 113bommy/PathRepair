#include <bits/stdc++.h>
int v, min_idx, costs[10];
char answer[1000005];
int main() {
  scanf("%d", &v);
  for (int i = 1; i <= 9; i++) scanf("%d", &costs[i]);
  min_idx = 9;
  for (int i = 9; i >= 1; i--)
    if (costs[i] < costs[min_idx]) min_idx = i;
  int length = v / costs[min_idx];
  v %= costs[min_idx];
  memset(answer, '0' + min_idx, length);
  for (int i = 0; i < length; i++) {
    for (int j = 9; j > min_idx; j--) {
      if (v + costs[min_idx] >= costs[j]) {
        answer[i] = '0' + j;
        v = v + costs[min_idx] - costs[j];
        break;
      }
    }
  }
  printf("%s\n", length == 0 ? "-1" : answer);
  return 0;
}
