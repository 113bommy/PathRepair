#include <bits/stdc++.h>
using namespace std;
const int N = 300;
int t, a[N];
int main() {
  scanf("%d", &t);
  while (t--) {
    double sum = 0, fan = 0;
    for (int i = (1); i <= (250); ++i) scanf("%d", a + i), sum += a[i];
    sum /= 250;
    for (int i = (1); i <= (250); ++i) fan += (a[i] - sum) * (a[i] - sum);
    if (fan > sum * 500)
      puts("uniform");
    else
      puts("poisson");
  }
  return 0;
}
