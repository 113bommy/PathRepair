#include <bits/stdc++.h>
using namespace std;
long long sqp(long long x) {
  long long s = 1;
  long long e = 1000000000;
  long long ans;
  if (x == 0 || x == 1) return x;
  while (s <= e) {
    long long mid = (s + e) / 2;
    if (mid * mid == x) return mid;
    if (mid * mid < x) {
      s = mid + 1;
      ans = mid;
    } else {
      e = mid - 1;
    }
  }
  return ans;
}
void dfs(int i, vector<vector<int> > &v, vector<bool> &vis, vector<int> &dep,
         vector<int> &sz) {
  vis[i] = true;
  sz[i] = 1;
  for (auto u : v[i]) {
    if (vis[u] == false) {
      dep[u] = dep[i] + 1;
      dfs(u, v, vis, dep, sz);
      sz[i] = sz[i] + sz[u];
    }
  }
}
void bfs(vector<vector<int> > &v) {}
bool cmp(pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b) {
  if (a.first.first == b.first.first) {
    return a.first.second < b.first.second;
  } else
    return a.first.first < b.first.first;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, m;
  cin >> n >> m;
  long long x;
  vector<long long> a(n);
  vector<long long> b(m);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  cin >> x;
  vector<long long> aa(n + 1, LLONG_MAX);
  vector<long long> bb(m + 1, LLONG_MAX);
  aa[0] = 0;
  bb[0] = 0;
  for (int i = 1; i <= n; i++) {
    long long s = 0;
    for (int j = 0; j < i; j++) {
      s = s + a[j];
    }
    aa[i] = s;
    for (int j = i; j < n; j++) {
      s = s + a[j];
      s = s - a[j - i];
      aa[i] = min(aa[i], s);
    }
  }
  for (int i = 1; i <= m; i++) {
    long long s = 0;
    for (int j = 0; j < i; j++) {
      s = s + b[j];
    }
    bb[i] = s;
    for (int j = i; j < m; j++) {
      s = s + a[j];
      s = s - a[j - i];
      bb[i] = min(bb[i], s);
    }
  }
  long long c = 0;
  for (int i = 1; i <= n; i++) {
    long long y = aa[i];
    y = x / y;
    long long p = lower_bound(bb.begin(), bb.end(), y) - bb.begin();
    p = min(p, m);
    if (aa[i] * bb[p] <= x) {
      c = max(c, i * p);
    } else {
      c = max(c, i * (p - 1));
    }
  }
  cout << c << '\n';
}
