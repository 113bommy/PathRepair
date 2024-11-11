#include <bits/stdc++.h>
using namespace std;
double p[105];
int cnt[105];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lf", &p[i]);
    p[i] /= 100;
  }
  double now = 1.0;
  priority_queue<pair<double, int> > q;
  for (int i = 1; i <= n; i++) {
    now *= p[i];
    q.push(make_pair((1 - pow(1 - p[i], 2)) / p[i], i));
    cnt[i] = 1;
  }
  int tot = n;
  double res = now * tot, la = now;
  for (int _ = 1; _ <= 100000; _++) {
    pair<double, int> u = q.top();
    q.pop();
    now *= u.first;
    tot++;
    res += (now - la) * tot;
    la = now;
    int t = u.second;
    cnt[t]++;
    q.push(make_pair(
        (1 - pow(1 - p[t], cnt[t] + 1)) / (1 - pow(1 - p[t], cnt[t])), t));
  }
  printf("%.10f\n", res);
  return 0;
}
