#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000007;
struct way {
  int po, next, flow;
} e[2000010];
pair<int, int> q[1010];
int len, n, m, t, mx, pre[1010], numh[1010], cur[1010], h[1010], d[1010],
    p[1010];
int w[310][310], hs[310][310], a[310], b[310], r[310], ans[310];
vector<int> g[310][310];
string s;
bool v[310];
void add(int x, int y, int f) {
  e[++len].po = y;
  e[len].flow = f;
  e[len].next = p[x];
  p[x] = len;
}
void build(int x, int y, int f) {
  add(x, y, f);
  add(y, x, 0);
}
int sap() {
  memset(h, 0, sizeof(h));
  memset(numh, 0, sizeof(numh));
  numh[0] = t + 1;
  for (int i = 0; i <= t; i++) cur[i] = p[i];
  int j, u = 0, s = 0, neck = inf;
  while (h[0] < t + 1) {
    d[u] = neck;
    bool ch = 1;
    for (int i = cur[u]; i != -1; i = e[i].next) {
      j = e[i].po;
      if (e[i].flow > 0 && h[u] == h[j] + 1) {
        neck = min(neck, e[i].flow);
        cur[u] = i;
        pre[j] = u;
        u = j;
        if (u == t) {
          s += neck;
          while (u) {
            u = pre[u];
            j = cur[u];
            e[j].flow -= neck;
            e[j ^ 1].flow += neck;
          }
          neck = inf;
        }
        ch = 0;
        break;
      }
    }
    if (ch) {
      if (--numh[h[u]] == 0) return s;
      int q = -1, tmp = t;
      for (int i = p[u]; i != -1; i = e[i].next) {
        j = e[i].po;
        if (e[i].flow && h[j] < tmp) {
          tmp = h[j];
          q = i;
        }
      }
      cur[u] = q;
      h[u] = tmp + 1;
      numh[h[u]]++;
      if (u) {
        u = pre[u];
        neck = d[u];
      }
    }
  }
  return s;
}
bool check() {
  t = n;
  len = -1;
  memset(p, 255, sizeof(p));
  memset(v, 0, sizeof(v));
  memset(hs, 0, sizeof(hs));
  for (int i = 1; i <= n; i++) v[b[i]] = 1;
  int can = 0;
  for (int i = 1; i <= n; i++)
    if (v[i]) {
      int x = 0;
      if (!w[i][0])
        x = i;
      else
        x = i - (w[i][0] - 1) % i - 1;
      if (x) {
        hs[i][0] = ++t;
        q[t] = make_pair(i, 0);
        build(0, t, x);
        can += x;
      }
      for (int j = 1; j < r[i]; j++)
        if (!w[i][j]) {
          hs[i][j] = ++t;
          q[t] = make_pair(i, j);
          build(0, t, 1);
          can++;
        }
    }
  for (int i = 1; i <= n; i++) {
    if (a[i] < n + 1 && b[i] < n + 1) continue;
    if (a[i] == n + 1 && b[i] == n + 1) {
      for (int j = n + 1; j <= t; j++) build(j, i, 1);
    } else if (b[i] == n + 1) {
      for (int j = 1; j <= n; j++)
        if (hs[j][a[i]]) build(hs[j][a[i]], i, 1);
    } else if (a[i] == n + 1) {
      for (int j = 0; j < r[b[i]]; j++)
        if (hs[b[i]][j]) build(hs[b[i]][j], i, 1);
    }
    build(i, t + 1, 1);
  }
  t++;
  if (sap() < can)
    return 0;
  else
    return 1;
}
void print() {
  for (int i = n + 1; i < t; i++)
    for (int j = p[i]; j > -1; j = e[j].next) {
      int x = e[j].po;
      if (x && x <= n && !e[j].flow) {
        a[x] = q[i].second;
        b[x] = q[i].first;
      }
    }
  for (int i = 1; i <= n; i++)
    if (a[i] == n + 1 && b[i] == n + 1) {
      a[i] = 0;
      b[i] = 1;
    } else if (a[i] == n + 1) {
      a[i] = 1;
    } else if (b[i] == n + 1) {
      for (int j = 1; j <= n; j++)
        if (r[j] >= a[i]) {
          b[i] = j;
          break;
        }
    }
  for (int i = 1; i <= n; i++) g[b[i]][a[i]].push_back(i);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < g[i][0].size(); j += i) {
      for (int k = j; k < j + i - 1; k++) ans[g[i][0][k]] = g[i][0][k + 1];
      ans[g[i][0][j + i - 1]] = g[i][0][j];
    }
    for (int j = 1; j <= n; j++)
      for (int k = 0; k < g[i][j].size(); k++) ans[g[i][j][k]] = g[i][j - 1][0];
  }
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
}
int main() {
  scanf("%d\n", &n);
  mx = 0;
  for (int i = 1; i <= n; i++) {
    getline(cin, s);
    int l = s.length(), j;
    for (j = 0; j < l; j++) {
      if (s[j] == '?')
        a[i] = n + 1;
      else if (s[j] == ' ')
        break;
      else
        a[i] = a[i] * 10 + s[j] - '0';
    }
    j++;
    for (; j < l; j++) {
      if (s[j] == '?')
        b[i] = n + 1;
      else if (s[j] == ' ')
        break;
      else
        b[i] = b[i] * 10 + s[j] - '0';
    }
    if (a[i] < n + 1 && b[i] == n + 1) {
      if (a[mx] < a[i]) mx = i;
    } else
      w[b[i]][a[i]]++;
  }
  for (int i = 1; i <= n; i++)
    for (int j = n; j; j--)
      if (w[i][j]) {
        r[i] = j;
        break;
      }
  bool ff = 0;
  for (int i = 1; i <= n; i++) {
    int pr = r[i];
    if (r[i] < a[mx]) {
      r[i] = a[mx];
      b[mx] = i;
    }
    if (check()) {
      ff = 1;
      break;
    }
    b[mx] = n + 1;
    r[i] = pr;
  }
  if (!ff)
    puts("-1");
  else
    print();
  return 0;
}
