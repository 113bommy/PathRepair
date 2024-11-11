#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
const long long MOD = 998244353;
const int inf = 1 << 30;
const long long linf = 1LL << 60;
const double PI = 3.14159265358979323846;
int n;
int r[1000], c[1000];
int y[1000], x[1000];
int m;
pair<pair<int, int>, pair<int, int> > out[1000];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", c + i);
    y[--c[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", r + i);
    x[--r[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    if (x[i] == i && y[i] == i) continue;
    if (x[i] != i && y[i] != i) {
      out[m++] = pair<pair<int, int>, pair<int, int> >(
          pair<int, int>(i + 1, x[i] + 1), pair<int, int>(y[i] + 1, i + 1));
      x[r[i]] = x[i];
      swap(r[i], r[x[i]]);
      x[i] = i;
      y[c[i]] = y[i];
      swap(c[i], c[y[i]]);
      y[i] = i;
    } else if (x[i] != i) {
      out[m++] = pair<pair<int, int>, pair<int, int> >(
          pair<int, int>(i + 1, x[i] + 1), pair<int, int>(i + 1, i + 1));
      x[r[i]] = x[i];
      swap(r[i], r[x[i]]);
      x[i] = i;
    } else {
      out[m++] = pair<pair<int, int>, pair<int, int> >(
          pair<int, int>(i + 1, i + 1), pair<int, int>(y[i] + 1, i + 1));
      y[c[i]] = y[i];
      swap(c[i], c[y[i]]);
      y[i] = i;
    }
  }
  printf("%d\n", m);
  for (int i = 0; i < m; i++) {
    printf("%d %d %d %d\n", out[i].first.first, out[i].first.second,
           out[i].second.first, out[i].second.second);
  }
}
