#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, T, cas = 0;
  scanf("%d", &T);
  while (cas++ < T) {
    int k, maxn = -1000;
    double sum = 0;
    for (int i = 1; i <= 250; i++) {
      scanf("%d", &k);
      maxn = max(maxn, abs(k));
      sum += k * k;
    }
    sum = sqrt(sum / 250.0);
    if (maxn / sum < 2.0) {
      puts("uniform");
    } else
      puts("poisson");
  }
  return 0;
}
