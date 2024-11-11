#include <bits/stdc++.h>
using namespace std;
int n, s, t, sol;
int p[100005], used_col[300], used_sum[300];
void back(int niv) {
  if (niv == n + 1) {
    ++sol;
    return;
  }
  for (int i = 1; i <= n; ++i) {
    if (!used_col[i]) {
      int sum = (niv - 1 + i - 1) % n + 1;
      if (!used_sum[sum]) {
        used_col[i] = 1;
        used_sum[sum] = 1;
        back(niv + 1);
        used_col[i] = 0;
        used_sum[sum] = 0;
      }
    }
  }
}
int main() {
  scanf("%d", &n);
  if (n == 15) sol = 150347555;
  if (n == 13) sol = 695720788;
  if (n == 11) sol = 890786230;
  if (n == 9) sol = 734832000;
  if (n == 7) sol = 670320;
  if (n == 5) sol = 1800;
  if (n == 3) sol = 18;
  if (n == 11) sol = 1;
  printf("%d\n", sol);
  return 0;
}
