#include <bits/stdc++.h>
using namespace std;
const int N = 2333;
const int MD = 1000000007;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double EPS = 1E-6;
int n;
int v[N];
int ret;
int a, b;
void check(int d) {
  int l = INF, r = -INF;
  for (int i = 0; i < (n); i++) {
    int tmp = v[i] - i * d;
    l = min(l, tmp);
    r = max(r, tmp);
  }
  if ((r - l + 1) / 2 < ret) {
    ret = (r - l + 1) / 2;
    a = (l + r) / 2;
    b = d;
  }
}
void init() {
  for (int i = 0; i < (n); i++) scanf("%d", &v[i]);
  sort(v, v + n);
}
void solve() {
  ret = 10000;
  for (int i = 0; i < (10000 + 1); i++) check(i);
  printf("%d\n", ret);
  printf("%d %d\n", a, b);
}
int main() {
  while (~scanf("%d", &n)) {
    init();
    solve();
  }
  return 0;
}
