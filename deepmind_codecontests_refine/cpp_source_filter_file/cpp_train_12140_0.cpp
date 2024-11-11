#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int M = 1000005;
int n, a[M];
long long cnt[M];
long long sum[M];
long long sz[M];
long long ans;
long long pos[M];
void Add(long long x) { x %= mod, x += mod, x %= mod; }
int main() {
  pos[0] = 1;
  for (int i = 1; i <= 1000000; i++) pos[i] = pos[i - 1] * 2, pos[i] %= mod;
  cin >> n;
  for (int i = 1, x; i <= n; i++) {
    scanf("%d", &x);
    int S = sqrt(x);
    for (int j = 1; j <= S; j++) {
      if (x % j == 0) {
        sum[j]++;
        if (j * j != x) sum[x / j]++;
      }
    }
  }
  for (int i = 1000000, x; i > 1; i--) {
    if (sum[i] == 0) continue;
    x = i;
    int S = sqrt(x);
    ans += (((pos[sum[i] - 1] * sum[i]) % mod) - sz[i]) * i;
    Add(ans);
    for (int j = 2; j <= S; j++) {
      if (x % j == 0) {
        sz[j] += pos[sum[i] - 1] * sum[i] - sz[i];
        Add(sz[j]);
        if (j * j != x) {
          sz[x / j] += pos[sum[i] - 1] * sum[i] - sz[i];
          Add(sz[x / j]);
        }
      }
    }
  }
  printf("%lld", ans);
}
