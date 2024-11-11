#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  const int maxlevel = 100;
  vector<double> fi(maxlevel + 1, 0.0), oldfi(maxlevel + 1);
  for (int i = 1; i <= n; i++) {
    fi.swap(oldfi);
    for (int l = 1; l <= maxlevel; l++) {
      fi[l] = 0.0;
      fi[l] += (k - 1.0) / (1.0 * k) * oldfi[l];
      double p2 = 0.0;
      if (l + 1 <= maxlevel)
        p2 += (1.0 / (l + 1.0)) * (l + oldfi[l + 1]);
      else
        p2 += (1.0 / (l + 1.0)) * (l + 0.0);
      p2 += (1.0 * l) / (l + 1.0) * oldfi[l];
      p2 += l / 2.0;
      fi[l] += p2 * (1.0 / k);
    }
  }
  double ret = 1.0 * k * fi[1];
  printf("%.10f\n", ret);
  return 0;
}
