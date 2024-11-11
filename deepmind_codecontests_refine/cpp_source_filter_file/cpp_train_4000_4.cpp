#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
struct Node {
  int q, w;
  bool operator<(const Node &o) const { return w > o.w; }
} a[N];
int n, m;
long long sum[N];
bool check(long long x) {
  long long e_cnt = x * (x - 1);
  if (x & 1) return 1 + e_cnt / 2 <= n;
  return 1 + (x - 2) / 2 + e_cnt <= n;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; ++i) scanf("%d %d", &a[i].q, &a[i].w);
  sort(a + 1, a + m + 1);
  for (int i = 1; i <= m; ++i) sum[i] = sum[i - 1] + a[i].w;
  int l = 1, r = m, mid;
  while (r > l) {
    mid = l + r + 1 >> 1;
    if (check(mid))
      l = mid;
    else
      r = mid - 1;
  }
  cout << sum[l] << endl;
  return 0;
}
