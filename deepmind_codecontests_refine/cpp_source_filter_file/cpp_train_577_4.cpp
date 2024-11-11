#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int h, l[N], a[N][4], q[N], f, e;
inline void ask(int x) {
  if (l[x]) return;
  cout << "? " << x << endl;
  cin >> l[x];
  if (!l[x]) exit(0);
  for (int i = 1; i <= l[x]; i++) cin >> a[x][i];
}
inline void print(int x) { cout << "! " << x << endl; }
inline bool leaf(int x) { return l[x] == 1; }
void solve() {
  memset(l, 0, sizeof(l));
  cin >> h;
  if (!h) exit(0);
  f = e = 20;
  ask(1);
  if (l[1] == 2) return print(1);
  q[e] = 1;
  if (!leaf(1)) {
    q[++e] = a[1][1];
    while (1) {
      ask(q[e]);
      if (leaf(q[e])) break;
      if (l[q[e]] == 2) return print(q[e]);
      for (int i = 1; i <= 3; i++)
        if (a[q[e]][i] != q[e - 1]) {
          q[e + 1] = a[q[e]][i];
          ++e;
          break;
        }
    }
    q[--f] = a[1][2];
    while (1) {
      ask(q[f]);
      if (leaf(q[f])) break;
      if (l[q[f]] == 2) return print(q[f]);
      for (int i = 1; i <= 3; i++)
        if (a[q[f]][i] != q[f + 1]) {
          q[f - 1] = a[q[f]][i];
          --f;
          break;
        }
    }
  }
  int dep = h - ((e - f) / 2), cur = q[(e + f) / 2];
  while (1) {
    if (dep <= 4) {
      if (dep == 1) return print(cur);
      for (int i = 1; i <= l[cur]; i++)
        if (!l[a[cur][i]]) {
          cur = a[cur][i];
          break;
        }
      if (--dep == 1) return print(cur);
      if (dep == 2) {
        int t[20], ptr = 0;
        ask(cur);
        for (int i = 1; i <= l[cur]; i++)
          if (!l[a[cur][i]]) t[++ptr] = a[cur][i];
        for (int i = 1; i < ptr; i++) {
          ask(t[i]);
          if (l[t[i]] == 2) return print(t[i]);
        }
        return print(t[ptr]);
      } else {
        int t[20], tt[20], ptr = 0, p2 = 0;
        ask(cur);
        for (int i = 1; i <= l[cur]; i++)
          if (!l[a[cur][i]]) t[++ptr] = a[cur][i];
        for (int i = 1; i <= ptr; i++) {
          ask(t[i]);
          for (int j = 1; j <= l[t[i]]; j++)
            if (!l[a[t[i]][j]]) tt[++p2] = a[t[i]][j];
        }
        for (int i = 1; i < p2; i++) {
          ask(tt[i]);
          if (l[tt[i]] == 2) return print(tt[i]);
        }
        return print(tt[p2]);
      }
    }
    f = e = 0;
    q[++e] = cur;
    while (1) {
      ask(q[e]);
      if (leaf(q[e]) && e) break;
      if (l[q[e]] == 2) {
        print(q[e]);
        return;
      }
      for (int i = 1; i <= l[q[e]]; i++)
        if (!l[a[q[e]][i]]) {
          q[e + 1] = a[q[e]][i];
          ++e;
          break;
        }
    }
    cur = q[(e - h + dep) / 2];
    dep -= (e - h - dep) / 2;
  }
}
int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
