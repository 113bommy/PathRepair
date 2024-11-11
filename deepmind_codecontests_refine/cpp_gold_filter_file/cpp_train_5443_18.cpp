#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const int md = 1e9 + 7;
const int INF = 1e9;
ll pwmd(ll a, ll b) {
  ll ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % md;
    a = (a * a) % md;
    b = b >> 1;
  }
  return ans;
}
ll invmod(ll n) { return pwmd(n, md - 2); }
void test_case() {
  int l, r;
  scanf("%d%d", &l, &r);
  if (l < (r + 1) / 2.0) {
    printf("NO\n");
  } else {
    printf("YES\n");
  }
}
int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    test_case();
  }
  return 0;
}
