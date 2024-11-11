#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
pair<int, long long> C[maxn];
long long ans[maxn];
vector<pair<int, int> > Ql[maxn];
priority_queue<pair<int, int> > heap;
int n, m, da[maxn], stk[maxn], LMax[maxn];
struct Que {
  int l, r;
} q[maxn];
void update(int x, int add) {
  for (int i = x; i <= n; i += ((i) & (-i))) ++C[i].first, C[i].second += add;
}
pair<int, long long> query(int x) {
  pair<int, long long> ret = make_pair(0, 0ll);
  for (int i = x; i; i -= ((i) & (-i))) {
    ret.first += C[i].first;
    ret.second += C[i].second;
  }
  return ret;
}
void Solve() {
  int top = 0;
  while (!heap.empty()) heap.pop();
  for (int i = 1; i <= n; ++i) LMax[i] = 0, Ql[i].clear();
  for (int i = n; i >= 1; --i) {
    while (top && da[stk[top]] < da[i]) LMax[stk[top--]] = i;
    stk[++top] = i;
  }
  for (int i = 1; i <= n; ++i) heap.push(make_pair(LMax[i] + 1, i));
  for (int i = 1; i <= n; ++i) Ql[q[i].l].push_back(make_pair(q[i].r, i));
  heap.push(make_pair(-1, -1));
  for (int i = 1; i <= n; ++i) C[i] = make_pair(0, 0ll);
  for (int i = n; i >= 1; --i) {
    pair<int, int> u = heap.top();
    while (u.first >= i) {
      update(u.second, u.first);
      heap.pop();
      u = heap.top();
    }
    for (int k = 0, j, num; k < (int)Ql[i].size(); ++k) {
      j = Ql[i][k].first;
      pair<int, long long> qi = query(i - 1), qj = query(j);
      num = j - i + 1 - (qj.first - qi.first);
      ans[Ql[i][k].second] += 1ll * (i + j) * (j - i + 1) / 2 -
                              (qj.second - qi.second + 1ll * i * num);
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", &da[i]);
  for (int i = 1; i <= m; ++i) scanf("%d", &q[i].l);
  for (int i = 1; i <= m; ++i) {
    scanf("%d", &q[i].r);
    ans[i] = q[i].r - q[i].l + 1;
  }
  Solve();
  reverse(da + 1, da + n + 1);
  for (int i = 1; i <= n; ++i) {
    q[i].l = n - q[i].l + 1;
    q[i].r = n - q[i].r + 1;
    swap(q[i].l, q[i].r);
  }
  Solve();
  for (int i = 1; i <= m; ++i) printf("%I64d ", ans[i]);
  return 0;
}
