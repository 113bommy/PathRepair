#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long add(long long x, long long y, long long CMOD = MOD) {
  return (x + y + CMOD + CMOD) % CMOD;
}
long long mult(long long x, long long y, long long CMOD = MOD) {
  return add(x, 0) * add(y, 0) % CMOD;
}
long long fast_expo(long long x, long long y, long long CMOD = MOD) {
  if (x == 0) return 0;
  if (y == 0) return 1;
  long long ans = fast_expo(x, y / 2, CMOD);
  ans = mult(ans, ans, CMOD);
  if (y & 1) ans = mult(ans, x, CMOD);
  return ans;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long gen(long long x, long long y) {
  if (x == y) return x;
  return x + rng() % (y - x + 1);
}
const int TAM = 2000 + 100;
const long long INF = LLONG_MAX / 4;
int a[TAM];
vector<int> G[TAM];
int n;
int memo[TAM];
bool vis[TAM];
int dp(int pos) {
  if (pos >= n) return 0;
  if (vis[pos]) return memo[pos];
  vis[pos] = true;
  int ans = INT_MAX;
  for (auto x : G[pos]) {
    ans = min(ans, 1 + dp(x));
  }
  return memo[pos] = ans;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  vector<pair<int, int> > pre;
  vector<pair<int, int> > sgt;
  for (int x = 1; x <= 2000; x++) {
    for (int i = 0; i < n; i++) {
      if (a[i] == x) pre.push_back({i, i});
    }
    sort((pre).begin(), (pre).end());
    sgt.clear();
    for (int i = 0; i < pre.size(); i++) {
      G[pre[i].first].push_back(pre[i].second + 1);
    }
    for (int i = 0; i < pre.size(); i++) {
      int l = i + 1, h = (int)pre.size() - 1, m;
      while (h - l > 1) {
        m = l + (h - l) / 2;
        if (pre[i].second < pre[m].first)
          h = m;
        else
          l = m;
      }
      if (pre[i].second < pre[l].first)
        m = l;
      else if (pre[i].second < pre[h].first)
        m = h;
      else
        m = -1;
      if (m != -1 and pre[m].first == pre[i].second + 1) {
        sgt.push_back({pre[i].first, pre[m].second});
      }
    }
    swap(pre, sgt);
  }
  printf("%d\n", dp(0));
  return 0;
}
