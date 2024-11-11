#include <bits/stdc++.h>
using namespace std;
priority_queue<pair<double, int> > Q;
double a[128], b[128], p[128];
int n, m;
double ans, sum;
double f(int i) { return p[i] * a[i] / (1 - p[i]); }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int k;
    scanf("%d", &k);
    a[i] = k / 100.0;
    b[i] = 1 - a[i];
  }
  sum = 1;
  ans = n;
  for (int i = 1; i <= n; ++i) {
    p[i] = b[i];
    sum *= 1 - p[i];
    Q.push(make_pair(f(i), i));
    ans *= a[i];
  }
  for (int i = n + 1; i <= 300000; ++i) {
    int k = Q.top().second;
    Q.pop();
    ans += f(k) * sum * i;
    ans *= (1 - p[k] * b[k]) / (1 - p[k]);
    p[k] *= b[k];
    Q.push(make_pair(f(k), k));
  }
  printf("%.10lf\n", ans);
  return 0;
}
