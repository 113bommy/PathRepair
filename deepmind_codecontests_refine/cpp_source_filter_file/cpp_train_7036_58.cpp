#include <bits/stdc++.h>
using namespace std;
int a[260];
double logg[10010];
double logsum[10010];
double uniform_prob(int P, int k) {
  if (k >= 0 && k <= 2 * P) return -logg[2 * P + 1];
  return -1.0E+18;
}
double poisson_prob(int P, int k) {
  if (k < 0) return -1.0E+18;
  return logg[P] * k - P - logsum[k];
}
double get_uniform(int P) {
  int i;
  double ans = 0.0;
  for ((i) = 0; (i) < (int)(10); (i)++) ans += uniform_prob(P, a[i]);
  return ans;
}
double get_poisson(int P) {
  int i;
  double ans = 0.0;
  for ((i) = 0; (i) < (int)(10); (i)++) ans += poisson_prob(P, a[i]);
  return ans;
}
void main2(void) {
  char type = '?';
  int P = -1;
  double best = -1.0E+18;
  int i;
  for (i = 10; i <= 1000; i++) {
    double tmp = get_uniform(i);
    if (tmp > best) {
      best = tmp;
      type = 'u';
      P = i;
    }
    tmp = get_poisson(i);
    if (tmp > best) {
      best = tmp;
      type = 'p';
      P = i;
    }
  }
  cout << ((type == 'p') ? "poisson" : "uniform") << endl;
}
int main(void) {
  int TC, tc, i;
  for ((i) = 0; (i) < (int)(10000); (i)++) logg[i] = log(i);
  for ((i) = 0; (i) < (int)(10000); (i)++)
    logsum[i + 1] = logsum[i] + log(i + 1);
  cin >> TC;
  for ((tc) = 0; (tc) < (int)(TC); (tc)++) {
    for ((i) = 0; (i) < (int)(10); (i)++) scanf("%d", &a[i]);
    main2();
  }
  return 0;
}
