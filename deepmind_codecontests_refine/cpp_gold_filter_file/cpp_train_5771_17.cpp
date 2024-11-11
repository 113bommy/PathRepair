#include <bits/stdc++.h>
using namespace std;
const int N = 200100;
const long long INF = (long long)1e18;
int n, k, p[N], e[N];
long long f[N], a[N];
vector<int> v;
vector<int> g[N];
void add(int at, int by, long long t[]) {
  while (at < N) {
    t[at] += by;
    at |= (at + 1);
  }
}
long long query(int at, long long t[]) {
  long long ret = 0;
  while (at >= 0) {
    ret += t[at];
    at = (at & (at + 1)) - 1;
  }
  return ret;
}
long long ask(int from, int to, long long t[]) {
  return query(to, t) - query(from - 1, t);
}
long long get(long long len) {
  int low = 0;
  int high = N - 1;
  long long ret = 0;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (ask(0, mid, f) >= len) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  ret += ask(0, high, a);
  len -= ask(0, high, f);
  ret += low * len;
  return ret;
}
int main() {
  scanf("%d %d", &n, &k);
  memset(a, 0, sizeof a);
  memset(f, 0, sizeof f);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &p[i], &e[i]);
    add(e[i], 1, f);
    add(e[i], e[i], a);
    g[p[i]].push_back(i);
  }
  sort(p, p + n);
  k = n - k + 1;
  long long ans = INF;
  for (int i = 0; i <= n; i++) {
    v.clear();
    int cnt = lower_bound(p, p + n, i - 1) - p;
    for (int j = max(0, i - 1); j <= i; j++) {
      for (int k = 0; k < g[j].size(); k++) {
        int at = g[j][k];
        add(e[at], -1, f);
        add(e[at], -e[at], a);
        v.push_back(e[at]);
      }
    }
    sort(v.begin(), v.end());
    int y = 0;
    int d = k - cnt;
    bool ok = (cnt + v.size() >= k);
    long long ss = 0;
    while (ok && y < d) {
      ss += v[y];
      y++;
    }
    for (int j = y; j < v.size(); j++) {
      int at = v[j];
      add(at, 1, f);
      add(at, at, a);
    }
    if (ok) {
      ss += get(i - y);
      ans = min(ans, ss);
    }
    for (int j = 0; j < y; j++) {
      int at = v[j];
      add(at, 1, f);
      add(at, at, a);
    }
  }
  if (ans == INF) {
    puts("-1");
  } else {
    printf("%lld\n", ans);
  }
  return 0;
}
