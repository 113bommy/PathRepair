#include <bits/stdc++.h>
using namespace std;
int n;
int ans;
int mul[10];
char command[10][35];
void solve(int i) {
  if (i > ans) return;
  if (mul[i] == n) {
    printf("%d\n", ans);
    for (int j = 0; j < ans; j++) printf("%s\n", command[j]);
    exit(0);
  }
  int nw = mul[i];
  for (int j = i + 1; j <= ans; ++j) nw *= 9;
  if (nw < n) return;
  for (int j = 0; j <= i; ++j) {
    for (int k = 1; k <= 8; k <<= 1) {
      if ((mul[i + 1] = mul[j] * k) > n) break;
      if (k > 1)
        sprintf(command[i], "lea e%cx, [%d*e%cx]", i + 'b', k, j + 'a');
      else
        sprintf(command[i], "lea e%cx, [e%cx]", i + 'b', j + 'a');
      solve(i + 1);
    }
  }
  for (int j = 0; j <= i; ++j) {
    for (int jj = 0; jj <= i; ++jj) {
      for (int k = 1; k <= 8; k <<= 1) {
        if ((mul[i + 1] = mul[j] + mul[jj] * k) > n) break;
        if (k > 1)
          sprintf(command[i], "lea e%cx, [e%cx + %d*e%cx]", i + 'b', j + 'a', k,
                  jj + 'a');
        else
          sprintf(command[i], "lea e%cx, [e%cx + e%cx]", i + 'b', j + 'a',
                  jj + 'a');
        solve(i + 1);
      }
    }
  }
}
int main() {
  scanf("%d", &n);
  mul[0] = 1;
  for (ans = 1;; ++ans) solve(0);
  return 0;
}
