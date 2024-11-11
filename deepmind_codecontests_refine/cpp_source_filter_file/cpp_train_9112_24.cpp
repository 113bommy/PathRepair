#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int n, k;
bool isPossible(double amt) {
  double a_trans = 0, a_recv = 0;
  double alpha = 1 - (double)k / 100.0;
  for (int i = 0; i < n; ++i) {
    if (v[i] > amt)
      a_trans += v[i] - amt;
    else
      a_recv += amt - v[i];
  }
  if (a_trans * alpha >= a_recv) return 1;
  return 0;
}
int main() {
  scanf("%d%d", &n, &k);
  int x;
  double sum = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &x);
    sum += x;
    v.push_back(x);
  }
  double a_max = sum / n, a_min = 0;
  double a_pre;
  double a_mid = a_max;
  while (1) {
    a_pre = a_mid;
    a_mid = (a_max + a_min) / 2;
    if (isPossible(a_mid))
      a_min = a_mid;
    else
      a_max = a_mid;
    if (abs(a_mid - a_pre) <= 0.000001) break;
  }
  printf("%lf\n", a_mid);
  return 0;
}
