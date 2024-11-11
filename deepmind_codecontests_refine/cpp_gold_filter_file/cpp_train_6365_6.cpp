#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const long long mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
vector<long long> ff[maxn];
pair<long long, long long> p[maxn];
long long yu[maxn];
long long n, m, k, t, sum = 0;
bool check(long long po) {
  for (int i = 1; i <= m; i++) ff[i].clear();
  for (int i = 1; i <= n; i++)
    if (p[i].first / p[i].second + 1 < m) {
      yu[i] = p[i].first % p[i].second;
      ff[p[i].first / p[i].second + 1].push_back(i);
    }
  int now = 0;
  for (int i = 0; i <= m - 1; i++) {
    while (!ff[now].size() && now < m) now++;
    if (now >= m) return 1;
    if (now <= i) return 0;
    auto pos = ff[now].back();
    if (yu[pos] + po < p[pos].second)
      yu[pos] += po;
    else {
      ff[now].pop_back();
      long long qwq = now + (yu[pos] + po) / p[pos].second;
      yu[pos] = (yu[pos] + po) % p[pos].second;
      if (qwq < m) ff[qwq].push_back(pos);
    }
  }
  return 1;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) scanf("%lld", &p[i].first);
  for (int i = 1; i <= n; i++) scanf("%lld", &p[i].second);
  long long l = 0, r = 2e12 + 1, ans = -1;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (check(mid))
      ans = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  cout << ans;
}
