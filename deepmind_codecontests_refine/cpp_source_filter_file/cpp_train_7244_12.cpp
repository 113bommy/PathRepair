#include <bits/stdc++.h>
const int m = 250;
int n, a[m];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int i = 0; i < m; i++) scanf("%d", a + i);
    double var = 0.0;
    for (int i = 0; i < m; i++) {
      var += a[i] * a[i];
    }
    var /= (m - 1);
    double abs = 0.0;
    for (int i = 0; i < m; i++) {
      abs += std::abs(a[i]);
    }
    abs /= m - 1;
    int outside = 0;
    int k =
        (std::abs(*std::min_element(a, a + m)) + *std::max_element(a, a + m)) /
        4;
    for (int i = 0; i < m; i++) {
      if (std::abs(a[i]) > k) {
        outside++;
      }
    }
    int min = *std::min_element(a, a + m);
    int max = *std::max_element(a, a + m);
    bool pois;
    if (min >= -3) {
      pois = (-min != max);
    } else {
      pois = outside < 80;
    }
    printf("%s\n", pois ? "poisson" : "uniform");
  }
}
