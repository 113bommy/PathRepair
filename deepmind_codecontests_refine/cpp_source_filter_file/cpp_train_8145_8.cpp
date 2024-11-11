#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
vector<int> nxt[maxn];
bool snake[maxn];
vector<int> line;
int len = 0;
int maxl[maxn];
bool rev[maxn];
bool find(int i, int tar, int pre) {
  if (i == tar) {
    snake[i] = true;
    len++;
    line.push_back(i);
    return true;
  }
  bool s = false;
  for (int j : nxt[i]) {
    if (j == pre) continue;
    if (find(j, tar, i)) {
      s = true;
      break;
    }
  }
  if (s) snake[i] = true, len++, line.push_back(i);
  return s;
}
int findl(int i, int pre) {
  int maxL = 0;
  int rcnt = 0;
  for (int j : nxt[i]) {
    if (pre == j || snake[j]) continue;
    int l = findl(j, i);
    maxL = max(maxL, l);
  }
  maxl[i] = maxL + 1;
  return maxL + 1;
}
int findrev(int i, int pre) {
  int maxL = 0;
  int rcnt = 0;
  for (int j : nxt[i]) {
    if (pre == j) continue;
    int l = findrev(j, i);
    if (l >= len - 1) rcnt++;
    if (rev[j]) rcnt += 2;
    maxL = max(maxL, l);
  }
  if (rcnt >= 2) rev[i] = true;
  return maxL + 1;
}
int main() {
  int t = 0;
  cin >> t;
  while (t--) {
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 1; i <= n; ++i) {
      nxt[i].clear();
      snake[i] = false;
      rev[i] = false;
    }
    for (int i = 0; i < n - 1; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      nxt[u].push_back(v);
      nxt[v].push_back(u);
    }
    len = 0;
    line.clear();
    find(a, b, -1);
    for (int i : line) {
      findl(i, -1);
    }
    int la = min(maxl[a], len), lb = min(maxl[b], len);
    int lla = 0, llb = 0;
    for (;;) {
      int ta = la, tb = lb;
      bool x = true;
      while (lla < lb) {
        ta = max(min(maxl[line[len - 1 - lla]], len) - lla, ta);
        lla++;
        x = false;
      }
      while (llb < la) {
        tb = max(min(maxl[line[llb]], len) - llb, tb);
        llb++;
        x = false;
      }
      la = ta, lb = tb;
      if (x) break;
    }
    int l = maxl[b];
    int ll = INT32_MAX;
    for (int i = 0; i < l && i < len - 1; i++) {
      ll = min(ll, i - maxl[line[len - 1 - i]]);
      ll = max(ll, -(len - i - 1));
    }
    l = la;
    findrev(a, -1);
    bool ok = false;
    for (int i = 0; i < l && i < len - 1; i++) {
      if (rev[line[i]]) {
        ok = true;
        break;
      }
    }
    if (ok) {
      cout << "YES" << endl;
      continue;
    }
    for (int i = 1; i <= n; ++i) {
      rev[i] = false;
    }
    ok = false;
    ll = INT32_MAX;
    l = maxl[a];
    for (int i = 0; i < l && i < len - 1; i++) {
      ll = min(ll, i - maxl[line[i]]);
      ll = max(ll, -(len - i - 1));
    }
    l = lb;
    findrev(b, -1);
    for (int i = 0; i < l && i < len - 1; i++) {
      if (rev[line[len - 1 - i]]) {
        ok = true;
        break;
      }
    }
    ok ? puts("YES") : puts("NO");
  }
}
