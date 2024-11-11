#include <bits/stdc++.h>
using namespace std;
int in() {
  int x;
  return scanf("%d", &x), x;
}
template <typename T, typename... Args>
void in(T& x, Args&... args) {
  in(x);
  if (sizeof...(args)) in(args...);
}
template <class T, class L>
T& smax(T& x, L y) {
  return x < y ? x = y : x;
}
template <class T, class L>
T& smin(T& x, L y) {
  return x > y ? x = y : x;
}
const int maxn = 1e6 + 17;
int n, seg[maxn << 2], q, ans[maxn], mat[maxn];
char s[maxn];
vector<pair<int, int> > as[maxn];
int get(int st, int en, int l = 0, int r = n, int id = 1) {
  if (st <= l && r <= en) return seg[id];
  if (en <= l || r <= st) return 0;
  int mid = (l + r) / 2;
  return get(st, en, l, mid, id * 2) + get(st, en, mid, r, id * 2 + 1);
}
void add(int p, int v, int l = 0, int r = n, int id = 1) {
  if (r - l < 2) {
    seg[id] = v;
    return;
  }
  int mid = (l + r) / 2;
  if (p < mid)
    add(p, v, l, mid, id * 2);
  else
    add(p, v, mid, r, id * 2 + 1);
  seg[id] = seg[id * 2] + seg[id * 2 + 1];
}
int main() {
  scanf("%s", s), n = strlen(s);
  scanf("%d", &q);
  for (int x, y, i = 0; i < q; i++)
    scanf("%d%d", &x, &y), as[y - 1].push_back({x - 1, i});
  stack<int> st;
  for (int i = 0, c = s[i] == '('; i < n; i++, c = s[i] == '(') {
    if (!c && st.size()) {
      add(st.top(), 1);
      st.pop();
    } else
      st.push(i);
    for (auto q : as[i]) ans[q.second] = get(q.first, i) * 2;
  }
  for (int i = 0; i < q; i++) printf("%d ", ans[i]);
  putchar('\n');
  return 0;
}
