#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  long long r;
  while (b != 0) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long fpow(long long n, long long k, int p = (int)1e9 + 7) {
  long long r = 1;
  for (; k; k >>= 1) {
    if (k & 1) r = r * n % p;
    n = n * n % p;
  }
  return r;
}
const int MOD = (int)1e9 + 7;
const int INF = (int)1e9;
const long long LINF = (long long)1e18;
const long double PI = 2 * acos((long double)0);
const int maxn = 110;
int n, m;
int a[maxn];
void solve() {
  scanf("%d%d", &n, &m);
  for (int i = (0); i < (n); i++) {
    int k;
    scanf("%d", &k);
    for (int i = (0); i < (k); i++) {
      int d;
      scanf("%d", &d);
      d--;
      a[d] = 1;
    }
  }
  for (int i = (0); i < (n); i++)
    if (!a[i]) {
      printf("NO");
      return;
    }
  printf("YES");
}
int main() {
  solve();
  return 0;
}
