#include <bits/stdc++.h>
using namespace std;
const int N = 300001;
const long long MOD = 1e9 + 7;
int n, a, b;
map<long long, int> f;
map<pair<int, int>, int> f2;
int main() {
  scanf("%d%d%d", &n, &a, &b);
  long long ans = 0;
  for (int i = 0, x, vx, vy; i < n; i++) {
    scanf("%d%d%d", &x, &vx, &vy);
    ans += f[1ll * a * vx - vy] - f2[make_pair(vx, vy)];
    f[1ll * a * vx - vy]++;
    f2[make_pair(vx, vy)]++;
  }
  printf("%lld\n", ans * 2);
  return 0;
}
