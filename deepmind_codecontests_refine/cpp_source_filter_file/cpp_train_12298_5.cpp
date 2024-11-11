#include <bits/stdc++.h>
int wt(int min, int p1, int p2, int p3, int t1, int t2) {
  if (min <= t1) {
    return min * p1;
  } else if (min > t1 && min <= t1 + t2) {
    return t1 * p1 + (min - t1) * t2;
  } else {
    return t1 * p1 + t2 * p2 + (min - t1 - t2) * p3;
  }
}
int main() {
  int n, p1, p2, p3, t1, t2;
  std::cin >> n >> p1 >> p2 >> p3 >> t1 >> t2;
  int rlast = 0;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int li, ri;
    std::cin >> li >> ri;
    if (i > 0) {
      sum += wt(li - rlast, p1, p2, p3, t1, t2);
    }
    sum += p1 * (ri - li);
    rlast = ri;
  }
  std::cout << sum;
}
