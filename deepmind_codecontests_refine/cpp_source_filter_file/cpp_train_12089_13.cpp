#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
inline int readint() {
  int res = 0, f = 1;
  char c = 0;
  while (!isdigit(c)) {
    c = getchar();
    if (c == '-') f = -1;
  }
  while (isdigit(c)) res = res * 10 + c - '0', c = getchar();
  return res * f;
}
struct Node {
  int first, second, idx;
} pa[MAXN], pb[MAXN];
int n, m, a, b, x[MAXN], y[MAXN];
char str[MAXN];
int pre[MAXN], sa[MAXN], rk[MAXN], h[MAXN], height[MAXN];
inline void buildSA() {
  memset(pre, 0, sizeof(pre));
  for (int i = 1; i <= n; i++) pre[str[i]]++;
  for (int i = 1; i <= 255; i++) pre[i] += pre[i - 1];
  for (int i = 1; i <= n; i++) sa[pre[str[i]]--] = i;
  int tot = 0;
  for (int i = 1; i <= n; i++) {
    if (i > 1 && str[sa[i]] == str[sa[i - 1]])
      rk[sa[i]] = tot;
    else
      rk[sa[i]] = ++tot;
  }
  for (int j = 1; j <= n; j <<= 1) {
    memset(pre, 0, sizeof(pre));
    for (int i = 1; i <= n; i++)
      pa[i].first = rk[i], pa[i].second = i + j > n ? 0 : rk[i + j],
      pa[i].idx = i;
    for (int i = 1; i <= n; i++) pre[pa[i].second]++;
    for (int i = 1; i <= n; i++) pre[i] += pre[i - 1];
    tot = 0;
    for (int i = 1; i <= n; i++) pb[pre[pa[i].second]--] = pa[i];
    memset(pre, 0, sizeof(pre));
    for (int i = 1; i <= n; i++) pre[pb[i].first]++;
    for (int i = 1; i <= n; i++) pre[i] += pre[i - 1];
    for (int i = n; i >= 1; i--) pa[pre[pb[i].first]--] = pb[i];
    tot = 0;
    for (int i = 1; i <= n; i++) {
      if (i > 1 && pa[i].first == pa[i - 1].first &&
          pa[i].second == pa[i - 1].second)
        rk[pa[i].idx] = tot;
      else
        rk[pa[i].idx] = ++tot;
    }
  }
  for (int i = 1; i <= n; i++) sa[rk[i]] = i;
}
inline void getHeight() {
  int tmp, pos;
  for (int i = 1; i <= n; i++) {
    if (rk[i] == 1) continue;
    tmp = max(h[i - 1] - 1, 0);
    pos = sa[rk[i] - 1];
    while (tmp + pos <= n && tmp + i <= n && str[tmp + pos] == str[tmp + i])
      tmp++;
    h[i] = tmp;
  }
  for (int i = 1; i <= n; i++) height[rk[i]] = h[i];
}
int st[MAXN][19], bin[MAXN];
inline void buildST() {
  for (int i = 2; i <= n; i++) bin[i] = bin[i >> 1] + 1;
  for (int i = 1; i <= n; i++) st[i][0] = height[i];
  for (int j = 1; (1 << j) <= n; j++)
    for (int i = 1; i + (1 << j) - 1 <= n; i++)
      st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}
inline int query(int l, int r) {
  if (r < l) return (1 << 30);
  int k = bin[r - l + 1];
  return min(st[l][k], st[r - (1 << k) + 1][k]);
}
map<int, int> mq;
map<int, int>::iterator it;
pair<int, int> q[MAXN];
int now[MAXN];
long long tpre[MAXN][2], cpre[MAXN][2];
int cnt = 0;
inline long long solve(int l, int r) {
  if (l == r) return q[l].second == 3 ? n - sa[q[l].first] + 1 : 0;
  int mid = (l + r) >> 1;
  long long res = solve(l, mid) + solve(mid + 1, r);
  for (int i = l; i <= mid; i++) now[i] = query(q[i].first + 1, q[mid].first);
  for (int i = mid + 1; i <= r; i++)
    now[i] = query(q[mid].first + 1, q[i].first);
  tpre[mid][0] = tpre[mid][1] = 0;
  cpre[mid][0] = cpre[mid][1] = 0;
  for (int i = mid + 1; i <= r; i++) {
    tpre[i][0] = tpre[i - 1][0] + (q[i].second != 2 ? now[i] : 0);
    tpre[i][1] = tpre[i - 1][1] + (q[i].second != 1 ? now[i] : 0);
    cpre[i][0] = cpre[i - 1][0] + (q[i].second != 2);
    cpre[i][1] = cpre[i - 1][1] + (q[i].second != 1);
  }
  int pos1 = mid + 1, pos2 = mid + 1;
  for (int i = mid; i >= l; i--) {
    if (q[i].second != 2) {
      while (pos1 <= r && !(q[pos1].second != 1 && now[pos1] < now[i])) pos1++;
      res += tpre[r][1] - tpre[pos1 - 1][1] + cpre[pos1 - 1][1] * now[i];
    }
    if (q[i].second != 1) {
      while (pos2 < r && !(q[pos2].second != 2 && now[pos2] < now[i])) pos2++;
      res += tpre[r][0] - tpre[pos2 - 1][0] + cpre[pos2 - 1][0] * now[i];
    }
  }
  return res;
}
int main() {
  n = readint(), m = readint();
  scanf("%s", str + 1);
  buildSA(), getHeight(), buildST();
  while (m--) {
    a = readint(), b = readint();
    mq.clear();
    for (int i = 1; i <= a; i++) mq[rk[readint()]] += 1;
    for (int i = 1; i <= b; i++) mq[rk[readint()]] += 2;
    cnt = 0;
    for (it = mq.begin(); it != mq.end(); it++)
      q[++cnt] = make_pair(it->first, it->second);
    sort(q + 1, q + cnt + 1);
    printf("%lld\n", solve(1, cnt));
  }
  return 0;
}
