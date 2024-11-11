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
int rev[2][maxn];
int win, lost;
int s;
vector<pair<int, int> > ans;
bool flag[maxn];
bool check(int t) {
  int tmp = 0;
  int pos = 0;
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
    if (w == win) {
      s++;
      tmp++;
    } else
      tmp--;
    pos = min(k, l) + 1;
  }
  return tmp > 0;
}
void solve() {
  memset(cnt, 0, sizeof(cnt));
  memset(rev, -1, sizeof(rev));
  memset(flag, 0, sizeof(flag));
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    a[i] %= 2;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) cnt[j][i] = cnt[j][(i + n) % (n + 1)];
    cnt[a[i]][i] = cnt[a[i]][(i + n) % (n + 1)] + 1;
    if (rev[a[i]][cnt[a[i]][i]] == -1) rev[a[i]][cnt[a[i]][i]] = i;
  }
  win = a[n - 1];
  lost = win ^ 1;
  int t = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] == win) t++;
    if (2 * t > n - i) {
      if (flag[t]) continue;
      flag[t] = 1;
      s = 0;
      if (check(t)) ans.push_back(make_pair(s, t));
    }
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
