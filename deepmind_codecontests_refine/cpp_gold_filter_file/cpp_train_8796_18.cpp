#include <bits/stdc++.h>
using namespace std;
int n;
double R, v;
double s, f;
double ret;
int main() {
  scanf("%d", &n);
  scanf("%lf %lf", &R, &v);
  for (int i = 1; i <= n; i++) {
    scanf("%lf %lf", &s, &f);
    double len = f - s;
    ret = len - fmod(len, 2.0 * acos(-1) * R);
    len = fmod(len, 2.0 * acos(-1) * R);
    double l = 0.0;
    double r = 2.0 * acos(-1) * R;
    double pivot;
    while (abs((l + R * sin(l / R)) - len / 2.0) > 1e-9 * len / 2.0) {
      pivot = (l + r) / 2.0;
      if (pivot + R * sin(pivot / R) <= len / 2.0)
        l = pivot;
      else
        r = pivot;
    }
    printf("%0.9f\n", (ret + 2.0 * l) / v);
  }
  return 0;
}
