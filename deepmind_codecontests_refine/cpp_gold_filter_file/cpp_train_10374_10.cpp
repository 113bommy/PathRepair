#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100086;
pair<int, int> p[MAXN];
int out[MAXN];
int main() {
  int i, j, k;
  int m, n;
  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    scanf("%d", &p[i].first);
    p[i].second = i;
  }
  sort(p, p + n);
  k = 0;
  for (i = 0; i < n; ++i) {
    out[p[i].second] = max(0, k - p[i].second);
    k = max(k, p[i].second);
  }
  for (i = 0; i < n; ++i) printf("%d ", out[i] - 1);
  return 0;
}
