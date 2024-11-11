#include <bits/stdc++.h>
using namespace std;
long double pb[105];
long double now[105];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int p;
    scanf("%d", &p);
    pb[i] = 1.0 - (long double)p / 100.0;
  }
  long double ret = (long double)n, mul = 1.0;
  priority_queue<pair<long double, int> > que;
  for (int i = 0; i < n; i++) {
    now[i] = pb[i];
    mul *= 1.0 - now[i];
    que.push(
        pair<long double, int>((1.0 - now[i] * pb[i]) / (1.0 - now[i]), i));
  }
  ret += 1.0 - mul;
  for (int i = 0; i < 30000; i++) {
    pair<long double, int> p = que.top();
    que.pop();
    mul *= p.first;
    ret += 1.0 - mul;
    int v = p.second;
    now[v] *= pb[v];
    que.push(
        pair<long double, int>((1.0 - now[v] * pb[v]) / (1.0 - now[v]), v));
  }
  printf("%.10f\n", (double)ret);
  return 0;
}
