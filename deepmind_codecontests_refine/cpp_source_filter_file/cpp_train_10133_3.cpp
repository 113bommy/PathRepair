#include <bits/stdc++.h>
using namespace std;
double T[100005];
int n, a, d, t, v;
int main() {
  cin >> n >> a >> d;
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &t, &v);
    double tt = (v * 1.0) / a;
    if (0.5 * a * tt * tt >= d)
      T[i] = sqrt(d * 2 / a) + t;
    else {
      T[i] = tt + (d - 0.5 * a * tt * tt) / (v * 1.0) + t;
    }
    if (i != 1) T[i] = max(T[i - 1], T[i]);
    printf("%.7lf\n", T[i]);
  }
  return 0;
}
