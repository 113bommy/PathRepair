#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
using ll = long long;
int n, m, q, p[N], pos[N];
ll t, l[N], r[N], w[N], c[N], v[N];
inline bool chk(int a, int b, int c) {
  return (v[b + 1] - v[c + 1]) * (b - a) >= (v[a + 1] - v[b + 1]) * (c - a);
}
bool check(int d, int c) {
  ll sz = t;
  for (int i = m; i > c; --i) v[i] = max(v[i + 1], w[i]);
  for (int i = 1; i <= c; i++) v[i] = d, pos[i] = i;
  for (int i = m; i > 0; --i) sz -= v[i];
  for (int i = 1; i <= m; i++)
    if (w[i] != -1 && w[i] != v[i]) return 0;
  for (int i = 2; i <= m; i++)
    if (w[i] != -1 || i <= c)
      pos[i] = i;
    else
      pos[i] = pos[i - 1];
  if (sz < 0) return 0;
  for (int i = m; i > 0; --i) {
    if (pos[i] == i) continue;
    v[i] = max(v[i], v[i + 1]);
    while (v[i] < v[pos[i]] && sz >= i - pos[i]) ++v[i], sz = sz - i + pos[i];
  }
  p[p[0] = 1] = 0;
  for (int i = m; i > 0; --i) v[i] += v[i + 1];
  for (int i = 1; i <= m; i++) {
    while (p[0] >= 2 && chk(p[p[0] - 1], p[p[0]], i)) --p[0];
    p[++p[0]] = i;
  }
  int z = 1;
  for (int i = n; i >= 0; --i) {
    int x = n - i;
    if (v[p[z] + 1] + p[z] * i >= v[p[z + 1] + 1] + p[z + 1] * i &&
        z + 1 <= p[0])
      ++z;
    if (v[p[z] + 1] + 1ll * p[z] * i + l[x] < l[n]) return 0;
  }
  for (int i = n; i >= 0; --i) {
    int x = n - i;
    if (v[p[z] + 1] + p[z] * i >= v[p[z + 1] + 1] + p[z + 1] * i &&
        z + 1 <= p[0])
      ++z;
    if (v[p[z] + 1] + 1ll * p[z] * i + r[x] < t) return 0;
  }
  return 1;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> l[i] >> r[i];
  sort(l + 1, l + n + 1);
  sort(r + 1, r + n + 1);
  for (int i = 1; i <= n; i++) l[i] += l[i - 1], r[i] += r[i - 1];
  for (int i = 1; i <= m; i++) w[i] = -1;
  cin >> q;
  int z = 0;
  while (q--) {
    int t1, t2;
    cin >> t1 >> t2;
    w[t1] = t2;
    z = max(z, t2);
  }
  c[0] = -1;
  cin >> t;
  for (int i = 1; i <= m; i++)
    if (w[i] != -1)
      c[i] = w[i];
    else
      c[i] = c[i - 1];
  int ans = -1, vt = -1, ret = -1;
  ll sum = 0;
  int cnt = 0;
  for (int i = 1; i <= m; i++)
    if (c[i] != -1)
      sum += c[i];
    else
      ++cnt;
  for (int i = z; i <= n; i++)
    if (cnt * 1ll * i + sum >= t) {
      vt = i;
      break;
    }
  if (vt == -1 || !check(vt, 1)) {
    cout << -1 << ' ' << -1 << endl;
    return 0;
  }
  int l = 1, r = m;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(vt, mid))
      ans = mid, l = mid + 1;
    else
      r = mid - 1;
  }
  l = vt;
  r = n;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid, ans))
      ret = mid, l = mid + 1;
    else
      r = mid - 1;
  }
  cout << ans << ' ' << ret << endl;
  return 0;
}
