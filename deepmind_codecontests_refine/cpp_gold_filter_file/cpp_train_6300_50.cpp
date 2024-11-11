#include <bits/stdc++.h>
using namespace std;
priority_queue<pair<double, int> > q;
double p[120], pp[120];
int main() {
  int n;
  scanf("%d", &n);
  double sum = 1.0;
  for (int i = 1; i <= n; ++i) {
    int v;
    scanf("%d", &v);
    p[i] = v / 100.0, pp[i] = p[i];
    sum *= p[i];
    q.push(make_pair(1 - p[i], i));
  }
  double ans = n * sum;
  for (int i = n + 1; i <= 250000; ++i) {
    pair<double, int> tmp = q.top();
    q.pop();
    double u = tmp.first;
    int v = tmp.second;
    ans += u * sum * i;
    sum /= pp[v];
    pp[v] += (1.0 - pp[v]) * p[v];
    sum *= pp[v];
    q.push(make_pair((1.0 - pp[v]) / pp[v] * p[v], v));
  }
  printf("%.10f\n", ans);
  return 0;
}
