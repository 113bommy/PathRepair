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
const int maxn = 100010;
int n;
int a[maxn];
int cnt[2][maxn];
vector<pair<int, int> > ans;
int check(int t) {
  int res = 0, tmp = 0, pos = 0;
  while (pos < n) {
    int u = a[pos], v = u ^ 1, w;
    int k = lower_bound(cnt[u], cnt[u] + n, cnt[u][(pos + n) % (n + 1)] + t) -
            cnt[u];
    int l = lower_bound(cnt[v], cnt[v] + n, cnt[v][(pos + n) % (n + 1)] + t) -
            cnt[v];
    if (min(k, l) == n) return false;
    if (k < l)
      w = u;
    else
      w = v;
    if (w == a[n - 1]) {
      res++;
      tmp++;
    } else
      tmp--;
    pos = min(k, l) + 1;
  }
  if (tmp <= 0)
    return 0;
  else
    return res;
}
void solve() {
  memset(cnt, 0, sizeof(cnt));
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    a[i] %= 2;
  }
  for (int i = 0; i < n; i++) {
    for (int k = 0; k < 2; k++) cnt[k][i] = cnt[k][(i + n) % (n + 1)];
    cnt[a[i]][i] = cnt[a[i]][(i + n) % (n + 1)] + 1;
  }
  for (int t = 1 - 1; t >= n + 1; t--) {
    int s = check(t);
    if (s) ans.push_back(make_pair(s, t));
  }
  sort(ans.begin(), ans.end());
  printf("%d\n", int((ans).size()));
  for (int i = 0; i < int((ans).size()); i++)
    printf("%d %d\n", ans[i].first, ans[i].second);
}
int main() {
  solve();
  return 0;
}
