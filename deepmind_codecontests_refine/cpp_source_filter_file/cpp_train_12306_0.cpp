#include <bits/stdc++.h>
using namespace std;
void tempwj() {
  freopen("hash.in", "r", stdin);
  freopen("hash.out", "w", stdout);
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long qpow(long long a, long long b, long long mod) {
  a %= mod;
  long long ans = 1;
  while (b > 0) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
struct cmp {
  bool operator()(const pair<int, long long>& a,
                  const pair<int, long long>& b) {
    return a.second > b.second;
  }
};
int lb(int x) { return x & -x; }
const int inf = INT_MAX;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const long long mod = 1e9 + 7;
const int maxn = 2e5 + 10;
const int M = 1e6 + 2;
int num[100];
long long C[105][105];
int main() {
  int T;
  scanf("%d", &T);
  C[0][0] = 1;
  for (int i = 1; i <= 20; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
  }
  while (T--) {
    long long ans = 1;
    memset(num, 0, sizeof(num));
    long long n;
    scanf("%lld", &n);
    long long k = 2;
    while (n) {
      num[n % k]++;
      n /= k;
      k++;
    }
    k--;
    int nn = 0;
    for (int i = k; i >= 2; i--) {
      ans = ans * C[nn][num[i]];
      nn -= num[i];
      nn++;
    }
    ans = ans * C[nn][num[1]];
    if (num[0] == 0) {
      printf("%lld\n", ans);
      continue;
    } else
      num[0]--;
    long long ss = 1;
    nn = 0;
    for (int i = k - 1; i >= 2; i--) {
      ss = ss * C[nn][num[i]];
      nn -= num[i];
      nn++;
    }
    ss = ss * C[nn][num[1]];
    ans -= ss;
    printf("%lld\n", ans - 1);
  }
  return 0;
}
