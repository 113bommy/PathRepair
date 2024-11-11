#include <bits/stdc++.h>
long long q_pow(long long x, long long n, long long mod) {
  long long ret = 1;
  while (n) {
    if (n & 1) ret = x * ret % mod;
    x = x * x % mod;
    n >>= 1;
  }
  return ret;
}
long long __gcd(long long x, long long y) {
  if (!y) return x;
  return __gcd(y, x % y);
}
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
using namespace std;
const long long INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 100000 + 5;
int num[maxn];
int n;
bool check(int n, int cnt) {
  if (n == 1 && cnt != 0) return true;
  if (cnt == 0) return false;
  for (int i = 1; i < n; i++)
    if (num[i] >= 0 && num[i + 1] >= 0) return true;
  for (int i = 1; i < n - 1; i++)
    if (num[i] >= 0 && num[i + 1] >= 0) return true;
  return false;
}
signed main(int argc, char *argv[]) {
  if (argc == 2 && strcmp("-debug", argv[1]) == 0) {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int k;
    scanf("%d%d", &n, &k);
    int tmp;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &tmp);
      if (tmp > k)
        num[i] = 1;
      else if (tmp == k)
        num[i] = 0, cnt++;
      else
        num[i] = -1;
    }
    if (check(n, cnt))
      printf("yes\n");
    else
      printf("no\n");
  }
  return 0;
}
