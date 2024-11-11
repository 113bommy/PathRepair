#include <bits/stdc++.h>
using namespace std;
const long double EPS = 1e-9;
const int MAXN = 8e5 + 10;
int eq = 0;
int nc[MAXN];
int c[MAXN];
int a[MAXN];
int n;
int m;
int b[MAXN];
void read() {
  scanf("%d", &n);
  for (int i = 0; i < (int)n; ++i) scanf("%d", &a[i]);
  scanf("%d", &m);
  for (int i = 0; i < (int)m; ++i) {
    scanf("%d", &b[i]);
    --b[i];
    ++c[b[i]];
  }
}
void change(int i, int add) {
  eq -= c[i] == nc[i];
  nc[i] += add;
  eq += c[i] == nc[i];
}
int who(int pos) {
  pos %= 2 * n - 2;
  if (pos <= n - 1) {
    return pos;
  }
  pos -= n - 1;
  return n - 1 - pos;
}
int cnt_pref(int id, int len) {
  int cnt = len / (2 * n - 2);
  len %= 2 * n - 2;
  int r = len - 1;
  if (r < 0) {
    return cnt;
  }
  if (r <= n - 1) {
    return cnt + (id <= r);
  }
  ++cnt;
  int suff = r - (n - 1) + 1;
  return cnt + (id >= n - suff);
}
int main() {
  read();
  eq = 0;
  for (int i = 0; i < (int)n; ++i) eq += c[i] == 0;
  long long cur_dist = 0;
  for (int i = 0; i < (int)m - 1; ++i) {
    change(who(i), +1);
    cur_dist += abs(a[who(i)] - a[who(i + 1)]);
  }
  change(who(m - 1), +1);
  long long dist = -1;
  for (int l = 0, r = m; l < 2 * n - 1; ++l, ++r) {
    if (eq == n) {
      if (dist != -1 && cur_dist != dist) {
        puts("-1");
        return 0;
      }
      dist = cur_dist;
    }
    cur_dist -= abs(a[who(l)] - a[who(l + 1)]);
    cur_dist += abs(a[who(r - 1)] - a[who(r)]);
    change(who(l), -1);
    change(who(r), +1);
  }
  cout << dist << endl;
  return 0;
}
