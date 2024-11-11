#include <bits/stdc++.h>
using namespace std;
int TC, w[260];
double mean;
int main() {
  srand(1879);
  int i;
  scanf("%d", &TC);
  while (TC--) {
    mean = 0.0;
    for (i = 1; i <= 250; i++) {
      scanf("%d", &w[i]);
      mean += w[i];
    }
    mean /= 250;
    double res = 0.0;
    for (i = 1; i <= 250; i++) {
      if (mean - sqrt(mean) * 2 <= w[i] && w[i] <= sqrt(mean) * 2 + mean)
        res += 1.0 / 250;
    }
    if (res < 0.9)
      printf("uniform\n");
    else
      printf("poisson\n");
  }
}
