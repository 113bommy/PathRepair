#include <bits/stdc++.h>
using namespace std;
int d[5][5], t[5], ans = 0;
int analyze();
int main() {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) scanf("%d", &d[i][j]);
  }
  for (int i = 0; i < 5; i++) t[i] = i;
  do ans = max(ans, analyze());
  while (next_permutation(t, t + 5));
  printf("%d\n", ans);
}
int analyze() {
  int sum = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = i; j < 5; j += 2) sum += d[t[j]][t[j + 1]] + d[t[j + 1]][t[j]];
  }
  return sum;
}
