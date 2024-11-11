#include <bits/stdc++.h>
int main() {
  int a, n;
  std::cin >> a >> n;
  std::vector<int> months(n + 1);
  std::vector<int> mindivisor(n + 1);
  mindivisor[1] = 1;
  for (int i = 2; i < a + n; ++i) {
    if (mindivisor[i] == 0) {
      mindivisor[i] = 1;
      for (int j = i + i; j <= a + n; j += i) {
        if (mindivisor[j] == 0) mindivisor[j] = i;
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i < a + n; ++i) {
    int d = mindivisor[i];
    if (d == 1) {
      months[i] = i;
    } else {
      int p = months[i / d];
      months[i] = (p % d == 0 ? p / d : p * d);
    }
    if (i >= a) {
      ans += months[i];
    }
  }
  std::cout << ans << std::endl;
  return 0;
}
