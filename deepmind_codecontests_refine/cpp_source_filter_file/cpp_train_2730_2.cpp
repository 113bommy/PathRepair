#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int mod = 1000000007;
int n;
int ans[1000010], A[1000010], val[1000010];
int que[1000010], tot, L[1000010], R[1000010];
vector<pair<int, int> > G[1000010];
const int maxn = 1000010;
template <class T>
struct SMT {
  T t[maxn << 2], st[maxn << 2];
  void clear() { memset(t, 0, sizeof(t)); }
  void push_down(int p) {
    if (st[p]) {
      st[p << 1] = min(st[p << 1], st[p]);
      t[p << 1] = min(t[p << 1], st[p]);
      st[p << 1 | 1] = min(st[p << 1 | 1], st[p]);
      t[p << 1 | 1] = min(t[p << 1 | 1], st[p]);
      st[p] = 0;
    }
  }
  void update(int a, int b, T c, int p, int l, int r) {
    if (a <= l && r <= b) {
      t[p] = min(t[p], c);
      st[p] = min(st[p], c);
      return;
    }
    int mid = ((l) + ((r) - (l)) / 2);
    push_down(p);
    if (a <= mid) update(a, b, c, p << 1, l, mid);
    if (b > mid) update(a, b, c, p << 1 | 1, mid + 1, r);
    t[p] = min(t[p << 1], t[p << 1 | 1]);
  }
  T query(int a, int b, int p, int l, int r) {
    if (a <= l && r <= b) {
      return t[p];
    }
    int mid = ((l) + ((r) - (l)) / 2);
    push_down(p);
    T res = t[p];
    if (a <= mid) res = min(res, query(a, b, p << 1, l, mid));
    if (b > mid) res = min(res, query(a, b, p << 1 | 1, mid + 1, r));
    return res;
  }
};
SMT<int> smt;
void Dfs(int p) {
  if (val[p]) {
    que[++tot] = p;
  }
  L[p] = tot + (val[p] == 0);
  for (int i = 0; i <= ((int)(G[p]).size()) - 1; ++i) {
    Dfs(G[p][i].second);
  }
  R[p] = tot;
}
void Solve(int p, int num) {
  if (val[p]) {
    int res = smt.query(L[p], L[p], 1, 1, n);
    ans[p] = min(num, res + L[p]);
    num = min(num, ans[p]);
  }
  int now = num + 1 - L[p];
  if (now < 0 && R[p] > L[p]) smt.update(L[p], R[p], now, 1, 1, n);
  for (int i = 0; i <= ((int)(G[p]).size()) - 1; ++i) {
    Solve(G[p][i].second, num + 1);
  }
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  int tmax = 0;
  for (int i = 1; i <= n; ++i) {
    int p;
    char s[2];
    cin >> p >> s;
    G[p].push_back(make_pair(s[0] - 'a', i));
    tmax = max(tmax, p);
  }
  for (int i = 0; i <= tmax; ++i) sort(G[i].begin(), G[i].end());
  int K;
  cin >> K;
  for (int i = 1; i <= K; ++i) {
    cin >> A[i];
    val[A[i]] = 1;
  }
  Dfs(0);
  Solve(0, 0);
  for (int i = 1; i <= K; ++i) {
    cout << ans[A[i]] << " ";
  }
  cout << '\n';
  return 0;
}
