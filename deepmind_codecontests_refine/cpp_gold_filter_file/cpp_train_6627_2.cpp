#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
struct node {
  int x, y;
  friend bool operator<(node a, node b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
  }
};
map<long long, long long> p;
map<node, long long> same;
int main() {
  long long a, b, n, ans = 0, xx, vx, vy;
  ;
  scanf("%lld%lld%lld", &n, &a, &b);
  node cnt;
  for (int i = 0; i < n; i++) {
    scanf("%lld%lld%lld", &xx, &vx, &vy);
    cnt.x = vx, cnt.y = vy;
    long long ret = vy - vx * a;
    ans += p[ret] - same[cnt];
    p[ret]++;
    same[cnt]++;
  }
  printf("%lld\n", ans * 2);
  return 0;
}
