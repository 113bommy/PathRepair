#include <bits/stdc++.h>
int main(int argc, char** argv) {
  int n, m, flag = 0;
  long k = 0, result = 0;
  std::cin >> n >> m >> k;
  long long riad[1000];
  for (int i = 0; i < m; i++) {
    riad[i] = 1000000;
  }
  for (int i = 0; i < n; i++) {
    int r;
    long c;
    std::cin >> r >> c;
    if (riad[r - 1] > c) {
      riad[r - 1] = c;
    }
  }
  for (int i = 0; i < m; i++) {
    result += riad[i];
    if (result >= k) {
      std::cout << k;
      flag = 1;
      break;
    }
  }
  if (flag == 0) {
    printf("%li", result);
  }
}
