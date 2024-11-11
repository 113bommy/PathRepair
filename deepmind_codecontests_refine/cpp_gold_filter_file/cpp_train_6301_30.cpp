#include <bits/stdc++.h>
const int INF = 2147483647;
const int MOD = 1000000007;
const long long INF64 = 9223372036854775807;
const long double EPS = 1e-7;
using namespace std;
vector<int> a;
int getDist(int fr, int to) {
  int l = fr, r = to, mid = (a[to] + a[fr]) / 2;
  while (l < r - 1) {
    int m = (l + r) / 2;
    if (a[m] < mid)
      l = m;
    else
      r = m;
  }
  int l1 = fr, r1 = to, mid1 = (a[to] + a[fr]) / 2 + (a[to] + a[fr]) % 2;
  while (l1 < r1 - 1) {
    int m = (l1 + r1) / 2;
    if (a[m] < mid1)
      l1 = m;
    else
      r1 = m;
  }
  return min(
      min(max(a[l] - a[fr], a[to] - a[l]), max(a[r] - a[fr], a[to] - a[r])),
      min(max(a[l1] - a[fr], a[to] - a[l1]),
          max(a[r1] - a[fr], a[to] - a[r1])));
}
int main() {
  int n, k;
  char t;
  scanf("%d%d\n", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%c", &t);
    if (t == '0') a.push_back(i);
  }
  int ans = INF;
  for (int i = 0; i < (int)a.size() - k; i++) ans = min(ans, getDist(i, i + k));
  printf("%d\n", ans);
  return 0;
}
