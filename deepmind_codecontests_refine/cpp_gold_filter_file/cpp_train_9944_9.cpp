#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 20;
bool f[N];
vector<int> p;
int n, a, b, v[N];
int cost[N], pre[N], suf[N];
void sieve() {
  memset(f, 0x00, sizeof(f));
  for (int i = 2; i * i <= N; ++i) {
    if (f[i]) continue;
    for (int j = i + i; j < N; j += i) f[j] = true;
  }
  for (int i = 2; i < N; ++i)
    if (!f[i]) p.push_back(i);
}
int main() {
  sieve();
  scanf("%d%d%d", &n, &a, &b);
  for (int i = 0; i < n; ++i) scanf("%d", &v[i]);
  vector<int> values = {v[0],     v[0] - 1,     v[0] + 1,
                        v[n - 1], v[n - 1] - 1, v[n - 1] + 1};
  set<int> gcds;
  for (int i = 0; i < 6; ++i) {
    if (values[i] <= 1) continue;
    int t = values[i];
    for (int j = 0; p[j] * p[j] <= values[i] && t > 1; ++j) {
      if (t % p[j] == 0) {
        gcds.insert(p[j]);
        while (t % p[j] == 0) t /= p[j];
      }
    }
    if (t > 1) gcds.insert(t);
  }
  long long ans = (long long)1e18;
  for (auto gcd : gcds) {
    for (int i = 0; i < n; ++i) {
      if (v[i] % gcd == 0) {
        cost[i] = 0;
      } else if ((v[i] - 1) > 1 && (v[i] - 1) % gcd == 0) {
        cost[i] = 1;
      } else if ((v[i] + 1) > 1 && (v[i] + 1) % gcd == 0) {
        cost[i] = 1;
      } else {
        cost[i] = -1;
      }
    }
    for (int i = 0; i < n; ++i) {
      if (cost[i] == -1 || (i > 0 && pre[i - 1] == -1))
        pre[i] = -1;
      else
        pre[i] = cost[i] + (i > 0 ? pre[i - 1] : 0);
    }
    if (pre[n - 1] != -1) ans = min(ans, 1LL * pre[n - 1] * b);
    for (int i = n - 1; i >= 0; --i) {
      if (cost[i] == -1 || (i + 1 < n && suf[i + 1] == -1))
        suf[i] = -1;
      else
        suf[i] = cost[i] + (i + 1 < n ? suf[i + 1] : 0);
    }
    long long cur = a;
    long long sec = (long long)1e18;
    for (int r = 0; r < n; ++r) {
      if (r == n - 1) {
        ans = min(ans, sec + 1LL * r * a);
      }
      if (r + 1 < n && suf[r + 1] != -1) {
        ans = min(ans, cur + 1LL * suf[r + 1] * b + 1LL * r * a);
      }
      if (pre[r] != -1) {
        cur = min(cur, 1LL * pre[r] * b - 1LL * r * a);
        sec = min(sec, 1LL * pre[r] * b - 1LL * r * a);
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}
