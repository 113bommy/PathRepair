#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[1020304], f[1020304], lr[1020304];
int ch[1020304][2], calc[1020304];
int build(int l, int r) {
  pair<int, int> t = make_pair(-1, 0);
  for (int j = l; j <= r; ++j) t = max(t, make_pair(a[j].second, j));
  if (t.second > l) ch[t.second][0] = build(l, t.second - 1);
  if (t.second < r) ch[t.second][1] = build(t.second + 1, r);
  lr[t.second] = make_pair(l, r);
  return t.second;
}
int k, n, m;
pair<int, int> Ask(int t, int l, int r) {
  if (t == 0 || l > r) return make_pair(0, -(0x3f3f3f3f));
  if (lr[t].first >= l && lr[t].second <= r) {
    if (calc[t]) return f[t];
    calc[t] = true;
    pair<int, int> tl = Ask(ch[t][0], l, r), tr = Ask(ch[t][1], l, r);
    f[t].first = max(tl.second + max(tr.second, tr.first),
                     max(tl.second, tl.first) + tr.second) +
                 1;
    f[t].second = max(tr.second, tr.first) + max(tl.second, tl.first);
    return f[t];
  }
  if (l > t) return Ask(ch[t][1], l, r);
  if (r < t) return Ask(ch[t][0], l, r);
  pair<int, int> tl = Ask(ch[t][0], l, t - 1), tr = Ask(ch[t][1], t + 1, r);
  pair<int, int> tf;
  tf.first = max(tl.second + max(tr.second, tr.first),
                 max(tl.second, tl.first) + tr.second) +
             1;
  tf.second = max(tr.second, tr.first) + max(tl.second, tl.first);
  return tf;
}
int aa, b, c, d;
int main() {
  cin >> n >> k;
  for (int i = 1; i <= k; ++i) scanf("%d%d", &a[i].first, &a[i].second);
  cin >> aa >> b >> c >> d;
  for (int i = k + 1; i <= n; ++i)
    a[i].first = ((long long)a[i - 1].first * aa + b) % 1000000009;
  for (int i = k + 1; i <= n; ++i)
    a[i].second = ((long long)a[i - 1].second * c + d) % 1000000009;
  sort(a + 1, a + n + 1);
  int rt = build(1, n);
  cin >> m;
  for (int i = 1; i <= m; ++i) {
    if (i == 21) {
      int z = i;
    }
    int L, R;
    cin >> L >> R;
    int l = 1, r = n;
    while (l < r) {
      int mid = l + r >> 1;
      if (a[mid].first < L)
        l = mid + 1;
      else
        r = mid;
    }
    int tl = l;
    l = 1, r = n;
    while (l < r) {
      int mid = l + r + 1 >> 1;
      if (a[mid].first > R)
        r = mid - 1;
      else
        l = mid;
    }
    pair<int, int> A = Ask(rt, tl, l);
    if (A.first == 4) {
      int z = i;
    }
    printf("%d\n", max(A.first, A.second));
  }
  return 0;
}
