#include <bits/stdc++.h>
int solve(int n, int k) {
  int times = 240 - k;
  int prob = 0;
  while (prob < n && times - 5 * prob >= 0) {
    prob++;
    times -= 5 * prob;
  }
  return prob;
}
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  printf("%d", solve(n, k));
  return 0;
}
