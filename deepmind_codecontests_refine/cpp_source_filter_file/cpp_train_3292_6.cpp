#include <bits/stdc++.h>
using namespace std;
char s[200010];
int I[200010], H[200010], rk[200010], sa[200010];
int head[200010], buf[200010], nxt[200010], mn[200010][17];
pair<int, int> pos[200010];
void bucket_sort(int n) {
  int E = 0, m = max(n + 10, 256);
  for (int i = 0; i <= m; i++) head[i] = 0;
  for (int i = 0, u; i < n; i++) {
    u = pos[I[i]].second;
    buf[++E] = I[i];
    nxt[E] = head[u];
    head[u] = E;
  }
  for (int i = m, K = 0; i >= 0; i--) {
    for (int j = head[i]; j; j = nxt[j]) I[K++] = buf[j];
  }
  E = 0;
  for (int i = 0; i <= m; i++) head[i] = 0;
  for (int i = 0, u; i < n; i++) {
    u = pos[I[i]].first;
    buf[++E] = I[i];
    nxt[E] = head[u];
    head[u] = E;
  }
  for (int i = 0, K = 0; i <= m; i++) {
    for (int j = head[i]; j; j = nxt[j]) I[K++] = buf[j];
  }
}
void buildSA(int n) {
  for (int i = 0; i <= n; i++) rk[i] = s[i];
  for (int i = 0; i < 17; i++) {
    for (int j = 0; j < n; j++) {
      pos[j] = pair<int, int>(rk[j], rk[min(n, j + (1 << i))]);
      I[j] = j;
    }
    bucket_sort(n);
    int cnt = 0;
    pos[n] = pair<int, int>(-1, -1);
    I[n] = n;
    for (int j = 0; j < n; j++) {
      rk[I[j]] = cnt + 1;
      cnt += pos[I[j]] != pos[I[j + 1]];
    }
    if (cnt == n) break;
  }
  for (int i = 0; i < n; i++) sa[rk[i]] = i;
  for (int i = 0, h = 0; i < n; i++) {
    if (rk[i] == 1) continue;
    h = max(h - 1, 0);
    for (int j = sa[rk[i] - 1]; s[i + h] == s[j + h]; h++)
      ;
    H[rk[i]] = h;
  }
  for (int j = 1; j < 17; j++) {
    for (int i = 1; i <= n; i++) {
      if (i + (1 << j) - 1 > n) continue;
      if (j == 1)
        mn[i][j] = H[i + 1];
      else
        mn[i][j] = min(H[i + (1 << (j - 1))],
                       min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]));
    }
  }
}
int len;
int lcp(int u, int v) {
  if (u > v) swap(u, v);
  if (u == v) return len - sa[u];
  int rr = 31 - __builtin_clz(v - u + 1);
  return min(mn[u][rr], mn[v - (1 << rr) + 1][rr]);
}
int sum[200010];
char a[200010];
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cin >> len;
  cin >> s;
  long long ans = 0;
  cin >> a;
  for (int i = len - 1; i >= 0; i--) {
    if (a[i] == '0') {
      ans = i + 1;
      break;
    }
  }
  reverse(a, a + len);
  reverse(s, s + len);
  buildSA(len);
  for (int i = 1; i <= len; i++) {
    sum[i] = sum[i - 1];
    if (a[sa[i]] == '0') sum[i]++;
  }
  for (int i = 1; i <= len; i++) {
    int val = H[i];
    int St, Ed;
    int st = 0, ed = i;
    while (st < ed - 1) {
      int mid = (st + ed) >> 1;
      if (lcp(mid, i) >= val)
        ed = mid;
      else
        st = mid;
    }
    St = ed;
    st = i, ed = len + 1;
    while (st < ed - 1) {
      int mid = (st + ed) >> 1;
      if (lcp(mid, i) >= val)
        st = mid;
      else
        ed = mid;
    }
    Ed = st;
    ans = max(ans, (long long)val * (sum[Ed] - sum[St - 1]));
  }
  cout << ans << endl;
  return 0;
}
