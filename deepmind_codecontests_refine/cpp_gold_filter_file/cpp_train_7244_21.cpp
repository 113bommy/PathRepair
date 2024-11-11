#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)250 + 9;
const int M = 30;
const long long mod = 1000000007;
const double eps = 1e-14;
int v;
int p[maxn];
void init() {
  for (int i = 0; i < 250; i++) {
    scanf("%d", &p[i]);
  }
}
int main() {
  scanf("%d", &v);
  while (v--) {
    init();
    double e = 0;
    double d = 0;
    for (int i = 0; i < 250; i++) {
      d += (p[i] - e) * (p[i] - e) / 250;
    }
    double s = sqrt(d);
    int cnt = 0;
    for (int i = 0; i < 250; i++) {
      if (abs(p[i]) < 2 * s) {
        cnt++;
      }
    }
    if (cnt < 250) {
      printf("poisson\n");
    } else {
      printf("uniform\n");
    }
  }
  return 0;
}
