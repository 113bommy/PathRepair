#include <bits/stdc++.h>
using namespace std;
template <typename T>
void _R(T &x) {
  cin >> x;
}
void _R(int &x) { scanf("%d", &x); }
void _R(long long &x) { scanf("%" PRId64, &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template <typename T, typename... U>
void R(T &head, U &...tail) {
  _R(head);
  R(tail...);
}
template <typename T>
void _W(const T &x) {
  cout << x;
}
void _W(const int &x) { printf("%d", x); }
template <typename T>
void _W(const vector<T> &x) {
  for (auto i = x.cbegin(); i != x.cend(); i++) {
    if (i != x.cbegin()) putchar(' ');
    _W(*i);
  }
}
void W() {}
template <typename T, typename... U>
void W(const T &head, const U &...tail) {
  _W(head);
  putchar(sizeof...(tail) ? ' ' : '\n');
  W(tail...);
}
const int N = 2e5 + 10;
int n, k, a[N];
vector<int> e[N];
void make_tree(int p, int f) {
  if (f) e[p].erase(find(begin(e[p]), end(e[p]), f));
  for (int i : e[p]) make_tree(i, p);
}
bool good[N];
pair<bool, int> dp[N];
pair<bool, int> dfs1(int p) {
  bool fi = 1;
  int se = 0, mx = 0;
  for (int i : e[p]) {
    pair<bool, int> t = dfs1(i);
    fi &= t.first;
    if (t.first)
      se += t.second;
    else
      mx = max(mx, t.second);
  }
  se += mx;
  if (good[p])
    se++;
  else {
    fi = 0;
    se = 0;
  }
  return dp[p] = make_pair(fi, se);
}
int dfs2(int p, pair<bool, int> ft) {
  if (!good[p]) {
    int ans = 0;
    for (int i : e[p]) {
      int now = dfs2(i, pair<bool, int>(0, 0));
      ans = max(ans, now);
    }
    return ans;
  }
  int me = dp[p].second;
  if (ft.first) {
    me += ft.second;
  } else {
    int mx = 0;
    for (int i : e[p])
      if (!dp[i].first && dp[i].second > mx) mx = dp[i].second;
    if (ft.second > mx) me += ft.second - mx;
  }
  int ans = me;
  int mx1 = 0, mx2 = 0;
  for (int i : e[p]) {
    if (dp[i].first) continue;
    if (dp[i].second >= mx1) {
      mx2 = mx1;
      mx1 = dp[i].second;
    } else if (dp[i].second >= mx2) {
      mx2 = dp[i].second;
    }
  }
  if (!ft.first) {
    if (ft.second >= mx1) {
      mx2 = mx1;
      mx1 = ft.second;
    } else if (ft.second >= mx2) {
      mx2 = ft.second;
    }
  }
  int zf = 0;
  zf += !ft.first;
  for (int i : e[p]) zf += !dp[i].first;
  for (int i : e[p]) {
    pair<bool, int> nft;
    nft.first = (zf - !dp[i].first == 0);
    if (dp[i].first) {
      nft.second = me - dp[i].second;
    } else {
      if (dp[i].second == mx1) {
        nft.second = me - mx1 + mx2;
      } else {
        nft.second = me;
      }
    }
    int now = dfs2(i, nft);
    ans = max(ans, now);
  }
  return ans;
}
bool chk(int m) {
  for (int i = (1); i <= int(n); i++) good[i] = (a[i] >= m);
  dfs1(1);
  int now = dfs2(1, pair<bool, int>(1, 0));
  return now >= k;
}
int main() {
  R(n, k);
  for (int i = (1); i <= int(n); i++) R(a[i]);
  for (int i = 0; i < int(n - 1); i++) {
    int u, v;
    R(u, v);
    e[u].push_back(v);
    e[v].push_back(u);
  }
  make_tree(1, 0);
  int l = 1, r = 1000000;
  while (l != r) {
    int m = (l + r + 1) / 2;
    if (chk(m))
      l = m;
    else
      r = m - 1;
  }
  W(l);
  return 0;
}
