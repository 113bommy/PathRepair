#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
const double eps = 1e-6;
const double PI = acos(-1.);
const double E = 2.71828182845904523536;
const int MOD = (int)1e9 + 7;
const int INF = 0x3f3f3f3f;
const long long INFLL = 0x7f7f7f7f;
const int N = 1e5 + 7;
const int M = 2000000 + 5;
inline int popcnt(int x) { return __builtin_popcount(x); }
inline int clz(int x) { return __builtin_clz(x); }
inline int clz(long long x) { return __builtin_clzll(x); }
inline int lg2(int x) { return !x ? -1 : 31 - clz(x); }
inline int lg2(long long x) { return !x ? -1 : 63 - clz(x); }
int n, a[111111], c[111111];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) cin >> a[i], c[a[i]]++;
  int ans = 1;
  for (int i = 2; i <= 100000; i++) {
    int s = 0;
    for (int j = i; j <= 100000; j += i) {
      s += c[j];
    }
    ans = max(ans, s);
  }
  cout << ans << endl;
  return 0;
}
