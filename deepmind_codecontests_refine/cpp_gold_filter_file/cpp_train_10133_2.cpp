#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
using namespace std;
int t[100500];
int v[100500];
int main(int argc, char **argv) {
  int n, a, d;
  scanf("%d %d %d", &n, &a, &d);
  double ct = 0;
  for (int i = 0; i < (int)(n); ++i) {
    scanf("%d %d", t + i, v + i);
    double ctime = t[i];
    if (1ll * v[i] * v[i] <= 2ll * d * a) {
      ctime += 1.0 * v[i] / a + (1.0 * d - 1ll * v[i] * v[i] / 2.0 / a) / v[i];
    } else {
      ctime += sqrt(2.0 * d / a);
    }
    ct = max(ct, ctime);
    printf("%.10lf\n", ct);
  }
  return 0;
}
