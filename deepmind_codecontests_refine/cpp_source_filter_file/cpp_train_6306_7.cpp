#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, k;
int x[N], f[N], r[N];
vector<int> add[N];
vector<int> axis;
int bit[N];
inline void read(int &x) {
  x = 0;
  char c = getchar();
  while (isspace(c)) c = getchar();
  while (isdigit(c)) x = (x << 3) + (x << 1) + (c - '0'), c = getchar();
}
void upd(int x, int d) {
  while (x < N) {
    bit[x] += d;
    x += x & -x;
  }
}
int qry(int x) {
  int ret = 0;
  while (x) ret += bit[x], x -= x & -x;
  return ret;
}
int sv[3][N];
void input() {
  read(n);
  read(k);
  for (int i = 0; i < n; i++) {
    read(x[i]);
    read(r[i]);
    read(f[i]);
    axis.push_back(x[i]);
    axis.push_back(x[i] + r[i]);
    axis.push_back(x[i] - r[i]);
    add[f[i]].push_back(i);
  }
  axis.push_back(INT_MAX);
  axis.push_back(INT_MIN);
  sort(axis.begin(), axis.end());
  axis.resize(unique(axis.begin(), axis.end()) - axis.begin());
  for (int i = 0; i < n; i++)
    sv[0][i] = lower_bound(axis.begin(), axis.end(), x[i]) - axis.begin(),
    sv[1][i] =
        lower_bound(axis.begin(), axis.end(), x[i] - r[i]) - axis.begin(),
    sv[2][i] =
        lower_bound(axis.begin(), axis.end(), x[i] + r[i]) - axis.begin();
}
vector<int> all;
void push(int f) {
  for (auto i : add[f]) all.push_back(x[i]), all.push_back(x[i] + r[i] + 1);
}
int qry(int l, int r) { return qry(r + 1) - qry(l); }
long long calc(int idx) {
  if (all.size() == 0) return 0;
  long long ret = 0;
  sort(all.begin(), all.end());
  all.resize(unique(all.begin(), all.end()) - all.begin());
  vector<vector<int> > go, del;
  go.resize(all.size());
  del.resize(all.size());
  for (int i = max(0, idx - k); i <= min(10000, idx + k); i++) {
    for (auto v : add[i])
      go[lower_bound(all.begin(), all.end(), x[v]) - all.begin()].push_back(v),
          del[lower_bound(all.begin(), all.end(), x[v] + r[v] + 1) -
              all.begin()]
              .push_back(v);
  }
  for (int i = 0; i < all.size(); i++) {
    for (auto v : del[i]) {
      upd(sv[0][v] + 1, -1);
    }
    for (auto v : go[i]) {
      upd(sv[0][v] + 1, 1);
    }
    for (auto v : go[i]) {
      if (f[v] == idx) {
        ret += qry(sv[1][v], sv[2][v]) - 1;
      }
    }
  }
  return ret;
}
void solve() {
  long long ans = 0;
  for (int i = 0; i <= 10000; i++) {
    for (int j = max(0, i - k); j <= min(10000, i + k); j++) push(j);
    ans += calc(i);
    all.clear();
  }
  printf("%lld\n", ans);
}
int main() {
  input();
  solve();
  return 0;
}
