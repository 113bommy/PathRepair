#include <bits/stdc++.h>
using namespace std;
using namespace std;
int t1, t2, x1, x2, t0;
double f(pair<int, int> y) {
  if (y.second < 0) return -1e20;
  if (y.first + y.second == 0) return 0.0;
  return (1.0 * t1 * y.first + 1.0 * t2 * y.second) /
         (1.0 * y.first + 1.0 * y.second);
}
pair<int, int> best(pair<int, int> a, pair<int, int> b) {
  if (f(a) >= t0 && f(b) < t0) return a;
  if (f(b) >= t0 && f(a) < t0) return b;
  if (fabs(f(a) - t0) < fabs(f(b) - t0)) return a;
  return b;
}
int main() {
  scanf("%d %d %d %d %d", &t1, &t2, &x1, &x2, &t0);
  pair<int, int> ret = make_pair(0, 0), aux = make_pair(0, 0);
  int ini, fim, meio, p = 1000000000;
  for (int i = int(0); i <= int(x1); i++) {
    ini = 0, fim = x2;
    if (f(make_pair(i, ini)) >= t0) meio = 0;
    if (f(make_pair(i, fim)) <= t0)
      meio = fim;
    else
      for (meio = (ini + fim) / 2; ini <= fim; meio = (ini + fim) / 2) {
        if (f(make_pair(i, meio)) >= t0 && f(make_pair(i, meio - 1)) < t0)
          break;
        if (f(make_pair(i, meio)) >= t0)
          fim = meio - 1;
        else
          ini = meio + 1;
      }
    ret = best(ret, make_pair(i, meio));
  }
  if (ret.first) p = min(p, x1 / ret.first);
  if (ret.second) p = min(p, x2 / ret.second);
  printf("%d %d\n", ret.first * p, ret.second * p);
  return 0;
}
