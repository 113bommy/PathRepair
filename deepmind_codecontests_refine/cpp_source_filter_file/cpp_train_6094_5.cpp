#include <bits/stdc++.h>
using namespace std;
const int maxn = 6e5 + 5;
const int LOG = 35;
const int inf = 0x3f3f3f3f;
int n, m, pos[maxn], npos[maxn];
char s[maxn], t[maxn];
inline int read() {
  char ch = getchar();
  int u = 0, f = 1;
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    u = u * 10 + ch - 48;
    ch = getchar();
  }
  return u * f;
}
namespace SuffixArray {
int Sa[maxn], Rank[maxn], tmp[maxn], Height[maxn], tax[maxn];
inline void RadixSort(int n, int m) {
  for (int i = 0; i <= m; ++i) tax[i] = 0;
  for (int i = 1; i <= n; ++i) tax[Rank[i]]++;
  for (int i = 1; i <= m; ++i) tax[i] += tax[i - 1];
  for (int i = n; i >= 1; --i) Sa[tax[Rank[tmp[i]]]--] = tmp[i];
}
inline bool cmp(int x, int y, int w, int n) {
  return tmp[x] == tmp[y] &&
         (x + w > n ? -1 : tmp[x + w]) == (y + w > n ? -1 : tmp[y + w]);
}
inline void Build(char *s, int m) {
  int n = strlen(s + 1);
  for (int i = 1; i <= n; ++i) Rank[i] = s[i], tmp[i] = i;
  RadixSort(n, m);
  for (int i = 0, p = 0, w = 1; p < n; w <<= 1, m = p) {
    for (i = n - w + 1, p = 0; i <= n; ++i) tmp[++p] = i;
    for (i = 1; i <= n; ++i)
      if (Sa[i] > w) tmp[++p] = Sa[i] - w;
    RadixSort(n, m);
    swap(Rank, tmp);
    for (Rank[Sa[1]] = 1, i = 2, p = 1; i <= n; ++i)
      Rank[Sa[i]] = cmp(Sa[i - 1], Sa[i], w, n) ? p : ++p;
  }
  for (int i = 1, k = 0; i <= n; Height[Rank[i++]] = k)
    for (k -= k > 0; s[i + k] == s[Sa[Rank[i] - 1] + k]; ++k)
      ;
}
}  // namespace SuffixArray
using namespace SuffixArray;
int St[maxn][20], Len[maxn], be[maxn], ed[maxn], B, Q, nB, nbe[maxn], ned[maxn],
    lst, R, L;
pair<int, int> ans[maxn];
struct Query {
  int l, r, ql, qr, id;
  Query(int a = 0, int b = 0, int c = 0, int d = 0, int e = 0) {
    l = a;
    r = b;
    ql = c;
    qr = d;
    id = e;
  }
  bool operator<(const Query &t) const {
    return be[l] == be[t.l] ? r < t.r : be[l] < be[t.l];
  }
} q[maxn];
inline void BuildST() {
  Len[0] = -1;
  for (int i = 1; i <= n; ++i) Len[i] = Len[i >> 1] + 1, St[i][0] = Height[i];
  for (int j = 1; n >> j; ++j)
    for (int i = 1; i + (1 << j) - 1 <= n; ++i)
      St[i][j] = min(St[i][j - 1], St[i + (1 << j - 1)][j - 1]);
}
inline int Min(int l, int r) {
  if (l > r) swap(l, r);
  int k = Len[r - l + 1];
  return min(St[l][k], St[r - (1 << k) + 1][k]);
}
pair<int, int> w[maxn], o[maxn], CurAns;
stack<pair<int, pair<int, int> > > stb, st;
inline void UpdateBlock(int now) {
  if (lst < be[now]) {
    while (lst < be[now]) lst++;
    for (int i = 1; i <= ned[m]; ++i) w[i] = make_pair(0, ned[i - 1] + 1);
    for (int i = 1; i <= m; ++i) o[i] = make_pair(0, i);
    R = ed[lst];
  }
}
inline void add(int x, int ty) {
  x = pos[x];
  if (ty) st.push(make_pair(x, o[x])), stb.push(make_pair(nbe[x], w[nbe[x]]));
  o[x].first++;
  if (o[x].first > w[nbe[x]].first ||
      (o[x].first == w[nbe[x]].first && o[x].second < w[nbe[x]].second))
    w[nbe[x]] = o[x];
}
inline void query(int l, int r) {
  if (nbe[l] == nbe[r]) {
    for (int i = l; i <= r; ++i)
      if (o[i].first > CurAns.first) CurAns = o[i];
  } else {
    for (int i = l; nbe[l] == nbe[i]; ++i)
      if (o[i].first > CurAns.first) CurAns = o[i];
    for (int i = nbe[l] + 1; i < nbe[r]; ++i)
      if (w[i].first > CurAns.first) CurAns = w[i];
    for (int i = ned[nbe[r] - 1] + 1; i <= r; ++i)
      if (o[i].first > CurAns.first) CurAns = o[i];
  }
}
inline void RollBack() {
  while (st.size()) o[st.top().first] = st.top().second, st.pop();
  while (stb.size()) w[stb.top().first] = stb.top().second, stb.pop();
}
inline void CalcInBlock(int l, int r, int ql, int qr) {
  static int w[maxn];
  for (int i = l; i <= r; ++i) {
    int x = pos[i];
    w[x]++;
    if (x < ql || x > qr) continue;
    if (w[x] > CurAns.first || (w[x] == CurAns.first && x < CurAns.second))
      CurAns = make_pair(w[x], x);
  }
  for (int i = l; i <= r; ++i) w[pos[i]]--;
}
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  s[++n] = '$';
  m = read();
  for (int i = 1; i <= m; ++i) {
    scanf("%s", t + 1);
    for (int j = 1; t[j]; ++j) {
      s[++n] = t[j];
      npos[n] = i;
    }
    s[++n] = '$';
  }
  Build(s, 255);
  BuildST();
  Q = read();
  B = sqrt(n);
  for (int i = 1; i <= n; ++i) pos[i] = npos[Sa[i]];
  for (int i = 1; i <= n; ++i) be[i] = (i - 1) / B + 1, ed[be[i]] = i;
  nB = sqrt(m);
  for (int i = 1; i <= m; ++i) nbe[i] = (i - 1) / nB + 1, ned[nbe[i]] = i;
  for (int i = 1; i <= Q; ++i) {
    int ql = read(), qr = read(), L = read(), R = read(), Rl = Rank[L],
        Rr = Rank[L];
    int l = Rank[L] + 1, r = n, mid = l + r >> 1;
    while (l <= r) {
      mid = l + r >> 1;
      if (Min(Rank[L] + 1, mid) >= R - L + 1)
        l = mid + 1, Rr = mid;
      else
        r = mid - 1;
    }
    l = 1;
    r = Rank[L] - 1;
    while (l <= r) {
      mid = l + r >> 1;
      if (Min(mid + 1, Rank[L]) >= R - L + 1)
        r = mid - 1, Rl = mid;
      else
        l = mid + 1;
    }
    q[i] = Query(Rl, Rr, ql, qr, i);
  }
  sort(q + 1, q + 1 + Q);
  for (int i = 1; i <= Q; ++i) {
    CurAns = make_pair(0, q[i].ql);
    if (be[q[i].l] == be[q[i].r]) {
      CalcInBlock(q[i].l, q[i].r, q[i].ql, q[i].qr);
      ans[q[i].id] = CurAns;
      continue;
    }
    UpdateBlock(q[i].l);
    L = ed[lst] + 1;
    while (q[i].r > R) add(++R, 0);
    while (q[i].l < L) add(--L, 1);
    query(q[i].ql, q[i].qr);
    ans[q[i].id] = CurAns;
    RollBack();
  }
  for (int i = 1; i <= Q; ++i) printf("%d %d\n", ans[i].second, ans[i].first);
  return 0;
}
