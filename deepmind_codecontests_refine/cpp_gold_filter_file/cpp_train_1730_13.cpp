#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000000 + 10;
bool vis[maxn];
int pcnt, prime[150000];
void preprocess() {
  for (long long i = 2; i < maxn; i++) {
    if (!vis[i]) prime[pcnt++] = i;
    for (int j = 0; j < pcnt; j++) {
      if (i * prime[j] >= maxn) break;
      vis[i * prime[j]] = true;
      if (i % prime[j] == 0) break;
    }
  }
}
int n, x, y;
long long cnt[maxn], pre[maxn];
int main() {
  preprocess();
  int maxv = 1;
  scanf("%d%d%d", &n, &x, &y);
  while (n--) {
    int t;
    scanf("%d", &t);
    if (t > maxv) maxv = t;
    cnt[t]++;
    pre[t] += t;
  }
  for (int i = 1; i < maxn; i++) {
    cnt[i] += cnt[i - 1];
    pre[i] += pre[i - 1];
  }
  long long ans = 0x3f3f3f3f3f3f3f3f;
  int d = (x + y - 1) / y;
  for (int i = 0; i < pcnt && prime[i] <= maxv * 2; i++) {
    long long tmp = 0;
    int& p = prime[i];
    for (int k = p; k <= maxv * 2; k += p) {
      int f = k - min(d, p);
      tmp += (cnt[f] - cnt[k - p]) * x;
      tmp += ((cnt[k] - cnt[f]) * k - (pre[k] - pre[f])) * y;
    }
    if (tmp < ans) ans = tmp;
  }
  printf("%lld\n", ans);
  return 0;
}
