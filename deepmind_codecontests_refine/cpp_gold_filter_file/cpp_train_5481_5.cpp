#include <bits/stdc++.h>
int main(int argc, char** argv) {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);
  std::cout << std::fixed << std::setprecision(6);
  int k, a[2222], acc1[2222], acc2[2222];
  std::cin >> k;
  acc1[0] = acc2[0] = 0;
  for (int i = 0; i < k; i++) std::cin >> a[i];
  std::reverse(a, a + k);
  for (int i = 0; i < k; i++) {
    acc1[i + 1] = acc1[i] + (a[i] == 1 ? 1 : 0);
    acc2[i + 1] = acc2[i] + (a[i] == 2 ? 1 : 0);
  }
  int cp = 0;
  for (int i = 0; i < k; i++) {
    int dp1 = 0, dp2 = 0;
    for (int j = i; j < k; j++) {
      if (a[j] == 1) {
        dp1++;
      } else {
        dp2 = std::max(dp1 + 1, dp2 + 1);
      }
      cp = std::max(acc1[k] - acc1[j + 1] + std::max(dp1, dp2) + acc2[i], cp);
    }
  }
  std::cout << cp << std::endl;
  return 0;
}
