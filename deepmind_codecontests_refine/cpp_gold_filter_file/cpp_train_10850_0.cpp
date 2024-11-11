#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int n, m, q, p[N], pos[N];
long long t, l[N], r[N], w[N], c[N], v[N];
inline bool checkx(int i, int j, int k) {
  return ((v[j + 1] - v[k + 1]) * (j - i) >= (v[i + 1] - v[j + 1]) * (k - i));
}
inline bool check(int d, int c) {
  long long siz = t;
  for (int i = m; i > c; i--) v[i] = max(v[i + 1], w[i]);
  for (int i = 1; i <= c; i++) v[i] = d, pos[i] = i;
  for (int i = m; i >= 1; i--) siz -= v[i];
  for (int i = 1; i <= m; i++)
    if (w[i] != -1 && w[i] != v[i]) return false;
  for (int i = 2; i <= m; i++)
    if (w[i] != -1 || i <= c)
      pos[i] = i;
    else
      pos[i] = pos[i - 1];
  if (siz < 0) return false;
  for (int i = m; i >= 1; i--) {
    if (pos[i] == i) continue;
    v[i] = max(v[i], v[i + 1]);
    while (v[i] < v[pos[i]] && siz >= i - pos[i])
      v[i]++, siz = siz - i + pos[i];
  }
  p[p[0] = 1] = 0;
  for (int i = m; i >= 1; i--) v[i] = v[i] + v[i + 1];
  for (int i = 1; i <= m; i++) {
    while (p[0] >= 2 && checkx(p[p[0] - 1], p[p[0]], i)) p[0]--;
    p[++p[0]] = i;
  }
  int z = 1;
  for (int i = n; i >= 0; i--) {
    int x = n - i;
    if (v[p[z] + 1] + p[z] * i >= v[p[z + 1] + 1] + p[z + 1] * i &&
        z + 1 <= p[0])
      z++;
    if (v[p[z] + 1] + 1ll * p[z] * i + l[x] < l[n]) return false;
  }
  z = 1;
  for (int i = n; i >= 0; i--) {
    int x = n - i;
    if (v[p[z] + 1] + p[z] * i >= v[p[z + 1] + 1] + p[z + 1] * i &&
        z + 1 <= p[0])
      z++;
    if (v[p[z] + 1] + 1ll * p[z] * i + r[x] < t) return false;
  }
  return true;
}
int main() {
  cin >> n >> m;
  int a, b, z;
  long long v1 = 0, v2 = 0;
  z = 0;
  for (int i = 1; i <= n; i++) scanf("%lld%lld", &l[i], &r[i]);
  sort(l + 1, l + n + 1), sort(r + 1, r + n + 1);
  for (int i = 1; i <= n; i++) l[i] += l[i - 1], r[i] += r[i - 1];
  for (int i = 1; i <= m; i++) w[i] = -1;
  cin >> q;
  while (q--) scanf("%d%d", &a, &b), w[a] = b, z = max(z, b);
  c[0] = -1;
  cin >> t;
  for (int i = 1; i <= m; i++)
    if (w[i] != -1)
      c[i] = w[i];
    else
      c[i] = c[i - 1];
  int ans = -1, vt = -1, res = -1;
  long long sum = 0;
  int cnt = 0;
  for (int i = 1; i <= m; i++)
    if (c[i] != -1)
      sum += c[i];
    else
      cnt++;
  for (int i = z; i <= n; i++)
    if (1ll * cnt * i + sum >= t) {
      vt = i;
      break;
    }
  if (vt == -1 || !check(vt, 1)) {
    cout << -1 << " " << -1 << endl;
    return 0;
  }
  int l = 1, r = m;
  while (l <= r) {
    int d = (l + r) >> 1;
    if (check(vt, d))
      ans = d, l = d + 1;
    else
      r = d - 1;
  }
  l = vt, r = n;
  while (l <= r) {
    int d = (l + r) >> 1;
    if (check(d, ans))
      res = d, l = d + 1;
    else
      r = d - 1;
  }
  cout << ans << " " << res << endl;
}
