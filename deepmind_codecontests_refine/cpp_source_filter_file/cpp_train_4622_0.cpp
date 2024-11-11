#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 111;
int n, d, a[N], x[N], y[N];
int dist(int _a, int _b) {
  return (abs(x[_a] - x[_b]) + abs(y[_a] - y[_b])) * d - a[_a];
}
int main() {
  scanf("%d%d", &n, &d);
  for (int i = (0); i <= (n - 3); ++i) scanf("%d", a + i);
  for (int i = (0); i <= (n - 1); ++i) scanf("%d%d", x + i, y + i);
  vector<int> p(n, -1), used(n), ln(n, INT_MAX);
  ln[0] = 0;
  for (int i = (0); i <= (n - 1); ++i) {
    int v = -1;
    for (int j = (0); j <= (n - 1); ++j) {
      if (!used[j] && (v == -1 || ln[j] < ln[v])) v = j;
    }
    if (v == -1) break;
    used[v] = true;
    for (int j = (0); j <= (n - 1); ++j) {
      if (!used[j] && ln[v] + dist(v, j) < ln[j]) ln[j] = ln[v] + dist(v, j);
    }
  }
  printf("%d\n", ln[n - 1]);
}
