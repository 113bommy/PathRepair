#include <bits/stdc++.h>
const long long MOD = 1e9 + 7;
const long long MAXN = 35000 + 1;
using namespace std;
long long readInt() {
  bool minus1 = false;
  long long result = 0;
  char ch;
  ch = getchar();
  while (true) {
    if (ch == '-') break;
    if (ch >= '0' && ch <= '9') break;
    ch = getchar();
  }
  if (ch == '-')
    minus1 = true;
  else
    result = ch - '0';
  while (true) {
    ch = getchar();
    if (ch < '0' || ch > '9') break;
    result = result * 10 + (ch - '0');
  }
  if (minus1)
    return -result;
  else
    return result;
}
int a[MAXN];
int maps[MAXN];
int last[MAXN];
int dp[55][MAXN];
int kek[MAXN];
int n, k;
vector<int> t[MAXN << 2];
void build(int v = 1, int tl = 1, int tr = n) {
  if (tl == tr) {
    t[v].push_back(last[tl]);
    return;
  }
  int tm = tl + tr >> 1;
  build(v + v, tl, tm);
  build(v + v + 1, tm + 1, tr);
  t[v].resize(tr - tl + 1);
  merge(t[v + v].begin(), t[v + v].end(), t[v + v + 1].begin(),
        t[v + v + 1].end(), t[v].begin());
}
int get(int l, int r, int v = 1, int tl = 1, int tr = n) {
  if (l > r) return 0;
  if (l <= tl && tr <= r)
    return t[v].end() - upper_bound(t[v].begin(), t[v].end(), r);
  if (tl > r || tr < l) return 0;
  int tm = tl + tr >> 1;
  return get(l, r, v + v, tl, tm) + get(l, r, v + v + 1, tm + 1, tr);
}
map<int, int> q[MAXN];
void go(int v, int l, int r, int optl, int optr) {
  if (l > r) return;
  int mid = (l + r) >> 1;
  int opt = mid;
  dp[v][mid] = 0;
  int cst = get(min(mid, optr) + 1, mid);
  for (int i = min(mid, optr); i >= min(optl, l); i--) {
    if (last[i] > mid) cst++;
    int tmp = cst + dp[v - 1][i - 1];
    if (dp[v][mid] < tmp) {
      dp[v][mid] = tmp;
      opt = i;
    }
  }
  go(v, l, mid - 1, optl, opt);
  go(v, mid + 1, r, opt, optr);
}
int tmp = 0;
int main() {
  n = readInt(), k = readInt();
  for (int i = 1; i <= n; i++) {
    a[i] = readInt();
  }
  for (int i = n; i >= 1; i--) {
    if (maps[a[i]]) {
      last[i] = maps[a[i]];
    } else {
      last[i] = n + 1;
    }
    maps[a[i]] = i;
  }
  build();
  for (int i = 1; i <= n; i++) {
    dp[1][i] = get(1, i);
  }
  for (int i = 2; i <= k; i++) {
    go(i, 1, n, 1, n);
  }
  cout << dp[k][n];
  return 0;
}
