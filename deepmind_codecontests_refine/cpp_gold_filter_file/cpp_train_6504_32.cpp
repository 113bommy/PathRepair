#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const long long INF64 = 1e18;
const long double EPS = 1e-7;
mt19937 myrand(time(NULL));
const int N = 4013;
int n, k, ans;
int a[N];
bool read() {
  if (scanf("%d", &n) != 1) return 0;
  n++;
  k = (1 << n) - 1;
  for (int i = 0; i < ((1 << n) - 2); i++) scanf("%d", &a[i]);
  return 1;
}
int dfsMax(int v) {
  if (v * 2 > k) return 0;
  int tmp1 = dfsMax(v * 2) + a[v * 2 - 2];
  int tmp2 = dfsMax(v * 2 + 1) + a[v * 2 - 1];
  ans += abs(tmp1 - tmp2);
  return max(tmp1, tmp2);
}
void solve() {
  ans = 0;
  dfsMax(1);
  printf("%d\n", ans);
}
int main() {
  while (read()) solve();
  return 0;
}
