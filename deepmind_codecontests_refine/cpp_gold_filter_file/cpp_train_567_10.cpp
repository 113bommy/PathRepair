#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:134217728")
using namespace std;
int n, m;
long long d[2 * 100100], a[2 * 100100];
pair<long long, int> F[8 * 100100], T[8 * 100100];
void readin() {
  scanf("%d%d", &n, &m);
  int u;
  for (int i = int(1); i <= int(n); i++) {
    scanf("%d", &u);
    d[i + 1] = d[i] + u;
  }
  for (int i = int(1); i <= int(n); i++) {
    scanf("%d", &u);
    a[i] = u;
  }
}
void init() {
  for (int i = int(n + 1); i <= int(2 * n - 1); i++) {
    d[i + 1] = d[i] + d[i - n + 1] - d[i - n];
    a[i] = a[i - n];
  }
}
void update1(int node, int lo, int hi, int u, long long val) {
  if (lo > hi) return;
  if (u < lo || u > hi) return;
  if (lo == hi) {
    F[node].first = val;
    F[node].second = u;
    return;
  }
  int mid = (lo + hi) / 2;
  update1(2 * node, lo, mid, u, val);
  update1(2 * node + 1, mid + 1, hi, u, val);
  if (F[2 * node].first > F[2 * node + 1].first) {
    F[node] = F[2 * node];
  } else {
    F[node] = F[2 * node + 1];
  }
}
pair<long long, int> getmax(int node, int lo, int hi, int u, int v) {
  if (lo > hi || u > v) return make_pair(0, 0);
  if (v < lo || hi < u) return make_pair(0, 0);
  if (u <= lo && hi <= v) return F[node];
  int mid = (lo + hi) / 2;
  pair<long long, int> x1 = getmax(2 * node, lo, mid, u, min(mid, v));
  pair<long long, int> x2 =
      getmax(2 * node + 1, mid + 1, hi, max(u, mid + 1), v);
  if (x1.first > x2.first) return x1;
  return x2;
}
void update2(int node, int lo, int hi, int u, long long val) {
  if (lo > hi) return;
  if (u < lo || u > hi) return;
  if (lo == hi) {
    T[node] = make_pair(val, u);
    return;
  }
  int mid = (lo + hi) / 2;
  update2(2 * node, lo, mid, u, val);
  update2(2 * node + 1, mid + 1, hi, u, val);
  if (T[2 * node].first < T[2 * node + 1].first) {
    T[node] = T[2 * node];
  } else {
    T[node] = T[2 * node + 1];
  }
}
pair<long long, int> getmin(int node, int lo, int hi, int u, int v) {
  if (lo > hi || u > v) return make_pair(1000000000000000LL, 0);
  if (v < lo || hi < u) return make_pair(1000000000000000LL, 0);
  if (u <= lo && hi <= v) return T[node];
  int mid = (lo + hi) / 2;
  pair<long long, int> x1 = getmin(2 * node, lo, mid, u, min(mid, v));
  pair<long long, int> x2 =
      getmin(2 * node + 1, mid + 1, hi, max(u, mid + 1), v);
  if (x1.first < x2.first) return x1;
  return x2;
}
long long getres(int u, int v) {
  if (u > v) return 0;
  pair<long long, int> k = getmax(1, 1, 2 * n - 1, u, v);
  pair<long long, int> t1 = getmax(1, 1, 2 * n - 1, k.second + 1, v);
  pair<long long, int> t2 = getmin(1, 1, 2 * n - 1, u, k.second - 1);
  long long ret = 0;
  if (t2.second != 0) ret = k.first - t2.first;
  if (t1.second != 0) ret = max(ret, t1.first - d[k.second] + 2 * a[k.second]);
  return ret;
}
void process() {
  for (int i = int(1); i <= int(2 * n - 1); i++) {
    update1(1, 1, 2 * n - 1, i, 2 * a[i] + d[i]);
    update2(1, 1, 2 * n - 1, i, d[i] - 2 * a[i]);
  }
  int u, v;
  while (m--) {
    scanf("%d%d", &u, &v);
    long long res = 0;
    if (u <= v) {
      res = getres(1, u - 1);
      res = max(res, getres(v + 1, u + n - 1));
      res = max(res, getres(v + n + 1, 2 * n - 1));
      printf("%I64d\n", res);
    } else {
      res = getres(v + 1, u - 1);
      res = max(res, getres(v + n + 1, u + n - 1));
      printf("%I64d\n", res);
    }
  }
}
void writeout() {}
void make() {
  freopen("in.txt", "wt", stdout);
  int N = 200000, M = 150000, Q = 300000;
  cout << N << endl;
  for (int i = 0; i < N; i++) cout << 1000000 - i << " ";
  exit(0);
}
int main() {
  readin();
  init();
  process();
  writeout();
  return 0;
}
