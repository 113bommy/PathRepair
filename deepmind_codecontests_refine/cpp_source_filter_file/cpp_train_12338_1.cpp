#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int n, s, a[N], f[N], g[N], nxt[N];
inline int dis(int a, int b) {
  int d = abs(a - b);
  return min(d, n - d);
}
inline int cwdis(int a, int b) {
  int d = b - a;
  return d < 0 ? d + n : d;
}
int calc2(int);
int calc1(int pos) {
  int &ret = f[pos];
  if (ret != -1) return ret;
  ret = INT_MAX / 2;
  for (int d = -1; d < 2; d += 2) {
    int p = -1;
    for (int i = 1; i < n; i++) {
      int pp = (pos + i * d + n) % n;
      if (a[pos] == a[pp]) {
        p = pp;
        break;
      }
    }
    if (p == -1)
      ret = min(ret, calc2(pos));
    else {
      int dd = d == 1 ? cwdis(p, pos) : cwdis(pos, p);
      ret = min(ret, calc2(pos) + dd);
    }
  }
  return ret;
}
int calc2(int pos) {
  int &ret = g[pos];
  if (ret != -1) return ret;
  if (nxt[pos] == INT_MAX) return ret = 0;
  ret = INT_MAX / 2;
  for (int i = 0; i < n; i++)
    if (a[i] == nxt[pos]) ret = min(ret, calc1(i) + dis(pos, i));
  return ret;
}
void dfs2(int);
void dfs1(int pos) {
  int cur = f[pos];
  for (int d = -1; d < 2; d += 2) {
    int p = -1;
    for (int i = 1; i < n; i++) {
      int pp = (pos + i * d + n) % n;
      if (a[pos] == a[pp]) {
        p = pp;
        break;
      }
    }
    if (p == -1) {
      if (cur == calc2(pos)) return dfs2(pos);
    } else {
      int dd = d == 1 ? cwdis(p, pos) : cwdis(pos, p);
      if (cur == calc2(p) + dd) {
        int cnt = 0;
        for (int i = 1; i < n; i++) {
          ++cnt;
          int pp = (pos + i * (-d) + n) % n;
          if (a[pos] == a[pp]) {
            cout << (d == 1 ? '-' : '+') << cnt << endl;
            cnt = 0;
          }
        }
        return dfs2(p);
      }
    }
  }
}
void dfs2(int pos) {
  int cur = g[pos];
  if (nxt[pos] == INT_MAX) return;
  for (int i = 0; i < n; i++)
    if (a[i] == nxt[pos] && cur == calc1(i) + dis(pos, i)) {
      int d = i - pos;
      if (d < 0) d += n;
      if (d <= n - d)
        cout << "+" << d << endl;
      else
        cout << "-" << n - d << endl;
      return dfs1(i);
    }
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> s;
  --s;
  for (int i = 0; i < n; i++) cin >> a[i];
  memset(f, -1, sizeof(f));
  memset(g, -1, sizeof(g));
  for (int i = 0; i < n; i++) {
    nxt[i] = INT_MAX;
    for (int j = 0; j < n; j++)
      if (a[i] < a[j]) nxt[i] = min(nxt[i], a[j]);
  }
  int ans = INT_MAX / 2, mn = *min_element(a, a + n);
  for (int i = 0; i < n; i++)
    if (a[i] == mn) ans = min(ans, calc1(i) + dis(s, i));
  cout << ans << endl;
  for (int i = 0; i < n; i++)
    if (ans == calc1(i) + dis(s, i)) {
      int d = i - s;
      if (d < n) d += n;
      if (d <= n - d)
        cout << "+" << d << endl;
      else
        cout << "-" << n - d << endl;
      dfs1(i);
      break;
    }
  return 0;
}
