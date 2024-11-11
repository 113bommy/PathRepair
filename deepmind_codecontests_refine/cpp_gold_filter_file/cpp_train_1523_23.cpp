#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
inline long long read() {
  char tempt = getchar();
  long long x = 0, f = 0;
  while (tempt < '0' || tempt > '9') f |= tempt == '-', tempt = getchar();
  while (tempt >= '0' && tempt <= '9')
    x = x * 10 + tempt - '0', tempt = getchar();
  return f ? -x : x;
}
inline long long qmi(long long m, long long k, long long p) {
  long long res = 1 % p, t = m;
  while (k) {
    if (k & 1) res = res * t % p;
    t = t * t % p;
    k >>= 1;
  }
  return res;
}
template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
const long long N = 5000 + 10;
const long long mod = 1e9 + 7;
long long dis[N][N];
pair<long long, long long> a[N];
long long color[N];
long long n;
long long fd(pair<long long, long long> a, pair<long long, long long> b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
}
bool dfs(long long u, long long c, long long mid) {
  color[u] = c;
  for (long long i = 1; i <= n; i++) {
    if (dis[u][i] <= mid) continue;
    if (color[i] != -1) {
      if (color[i] == c) return false;
    } else {
      if (!dfs(i, !c, mid)) return false;
    }
  }
  return true;
}
bool check(long long v) {
  memset(color, -1, sizeof color);
  for (long long i = 1; i <= n; i++) {
    if (color[i] == -1) {
      if (!dfs(i, 0, v)) return false;
    }
  }
  return true;
}
long long l, r;
void bfs(long long u, long long c) {
  queue<long long> heap;
  heap.push(u);
  color[u] = c;
  while (heap.size()) {
    auto t = heap.front();
    heap.pop();
    for (long long i = 1; i <= n; i++) {
      if (color[i]) continue;
      if (dis[i][t] > r) {
        color[i] = c;
        heap.push(i);
      }
    }
  }
}
signed main() {
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= n; j++) {
      dis[i][j] = fd(a[i], a[j]);
    }
  l = 0, r = 20000;
  while (l < r) {
    long long mid = (l + r) >> 1;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  cout << r << endl;
  long long num = 0;
  memset(color, 0, sizeof color);
  for (long long i = 1; i <= n; i++) {
    if (color[i] == 0) {
      bfs(i, ++num);
    }
  }
  cout << qmi(2, num, mod) << endl;
}
