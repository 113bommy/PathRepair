#include <bits/stdc++.h>
using namespace std;
vector<double> v;
int main() {
  int n;
  scanf("%d", &n);
  double a;
  for (int i = 0; i < n; i++) scanf("%lf", &a), v.push_back(a);
  sort(v.rbegin(), v.rend());
  double prod = 1 - v[0], p = v[0];
  for (int i = 1; i < n; i++) {
    if (prod - p < 0) break;
    double nprod = prod * (1 - v[i]);
    p = p + v[i] * (prod - p);
    prod = nprod;
  }
  printf("%.10lf\n", p);
}
