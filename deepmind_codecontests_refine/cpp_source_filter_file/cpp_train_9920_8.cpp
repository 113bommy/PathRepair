#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
const long long INF = 1e18 + 7;
const long long maxn = 1e6 + 700;
const int M = 1e6 + 8;
const long long mod = 1e9 + 7;
const double eps = 1e-9;
const double PI = acos(-1);
template <typename T>
inline void read(T &a) {
  char c = getchar();
  T x = 0, f = 1;
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  a = f * x;
}
long long n, m;
long long a[maxn];
int vis[maxn], f[maxn];
int mp[maxn];
int pos = 0;
int base;
int _work(int x) {
  if (pos == x) return 0;
  for (int k = 1; k <= n; k++) f[k] = 0;
  for (int k = 1; k <= n; k++)
    if (a[k] == pos)
      f[k] = -1;
    else if (a[k] == x)
      f[k] = 1;
  for (int k = 0; k <= 2 * n; k++) mp[k] = 0;
  int ans = 0;
  mp[base] = 1;
  for (int k = 1; k <= n; k++) {
    f[k] += f[k - 1];
    if (!mp[f[k] + base])
      mp[f[k] + base] = k + 1;
    else
      ans = max(ans, k - mp[f[k] + base] + 1);
  }
  return ans;
}
int c[maxn];
int mx = 0;
void add(int x) {
  c[vis[x]]--;
  if (!c[vis[x]] && mx == vis[x]) mx--;
  vis[x]++;
  c[vis[x]]++;
  if (vis[x] > mx) mx = vis[x];
}
void del(int x) {
  c[vis[x]]--;
  if (!c[vis[x]] && mx == vis[x]) mx--;
  vis[x]--;
  c[vis[x]]++;
  if (vis[x] > mx) mx = vis[x];
}
int __work(int x) {
  for (int k = 1; k <= n; k++) vis[k] = c[k] = 0;
  int l = 1, ans = 0;
  vis[0] = 1e9 + 7;
  mx = 0;
  for (int i = 1; i <= n; i++) {
    add(a[i]);
    while (l <= i && mx > x) {
      del(a[l]);
      l++;
    }
    if (c[mx] >= 2) ans = max(ans, i - l + 1);
  }
  return ans;
}
vector<int> v, g;
int main() {
  read(n);
  base = n;
  for (int i = 1; i <= n; i++) {
    read(a[i]);
    vis[a[i]]++;
  }
  int cot = 0, mx = 0;
  for (int i = 1; i <= 100; i++) {
    if (vis[i] > mx) {
      mx = vis[i];
      cot = 1;
      pos = i;
    } else if (vis[i] == mx)
      cot++;
  }
  if (cot > 1)
    printf("%lld\n", n);
  else {
    int block = sqrt(n);
    for (int i = 1; i <= n; i++) {
      if (vis[i] >= block)
        v.push_back(i);
      else
        g.push_back(vis[i]);
    }
    sort(g.begin(), g.end());
    g.erase(unique(g.begin(), g.end()), g.end());
    int res = 0;
    for (int x : v) res = max(res, _work(x));
    for (int i = 1; i <= block + 1; i++) res = max(res, __work(i));
    printf("%d\n", res);
    ;
  }
  return 0;
}
