#include <bits/stdc++.h>
using namespace std;
map<pair<int, int>, int> two;
vector<pair<int, int> > clouds;
int rk[600009], lim[600009], ans[600009], st[600009],
    top = 0, one[600009], other[600009], pos[600009], b[600009 * 4];
pair<int, int> qes[600009], c[600009];
void mdf(int o, int l, int r, int p, int w) {
  if (l == r) {
    b[o] = w;
    return;
  }
  int mid = (l + r) >> 1;
  if (p <= mid)
    mdf(o * 2, l, mid, p, w);
  else
    mdf(o * 2 + 1, mid + 1, r, p, w);
  b[o] = max(b[o * 2], b[o * 2 + 1]);
}
int query(int o, int l, int r, int u, int v) {
  if (l >= u && r <= v) return b[o];
  int mid = (l + r) >> 1;
  if (v <= mid)
    return query(o * 2, l, mid, u, v);
  else if (u > mid)
    return query(o * 2 + 1, mid + 1, r, u, v);
  else
    return max(query(o * 2, l, mid, u, mid),
               query(o * 2 + 1, mid + 1, r, mid + 1, v));
}
int main() {
  int n, C, m, use = 0, free = 0;
  scanf("%d%d", &n, &C);
  for (int i = 1, l, r; i <= n; i++) {
    scanf("%d%d%d", &l, &r, &c[i].first);
    c[i].second = i;
    clouds.push_back(make_pair(l, i)), clouds.push_back(make_pair(r, -i));
  }
  sort(c + 1, c + n + 1);
  for (int i = 1, k = n; i <= n; i++) {
    rk[c[i].second] = i;
    while (k && c[i].first + c[k].first > C) k--;
    lim[i] = k;
  }
  clouds.push_back(make_pair(2e9, 0));
  sort(clouds.begin(), clouds.end());
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) scanf("%d", &qes[i].first), qes[i].second = i;
  sort(qes + 1, qes + m + 1);
  for (int i = 0, j = 1; j <= m && i < clouds.size(); i++) {
    int now = clouds[i].first, k = st[1], t = st[2];
    if (i) now -= clouds[i - 1].first;
    if (top == 2 && c[rk[k]].first + c[rk[t]].first <= C) {
      pair<int, int> pp = make_pair(k, t);
      two[make_pair(k, t)] += now, two[make_pair(t, k)] += now;
      other[k] = max(other[k], two[pp] + one[t]);
      other[t] = max(other[t], two[pp] + one[k]);
      use = max(use, one[k] + one[t] + two[pp]);
    } else if (top == 1 && c[rk[k]].first <= C) {
      mdf(1, 1, n, rk[k], one[k] += now);
      use = max(use, one[k] + other[k]);
      int o = rk[k];
      if (o != 1 && lim[o])
        use = max(use, one[k] + query(1, 1, n, 1, min(o - 1, lim[o])));
      if (o != n && lim[o] > o)
        use = max(use, one[k] + query(1, 1, n, o + 1, lim[o]));
    } else if (!top)
      free += now;
    k = clouds[i].second;
    if (k > 0)
      st[pos[k] = ++top] = k;
    else
      t = pos[-k], pos[st[t] = st[top--]] = t;
    while (j <= m && qes[j].first <= free + use)
      ans[qes[j].second] = clouds[i].first - (free + use - qes[j].first), j++;
  }
  for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
  return 0;
}
