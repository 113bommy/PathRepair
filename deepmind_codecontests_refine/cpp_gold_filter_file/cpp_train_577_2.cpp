#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int h, num[maxn], ch[maxn][5], A1[maxn], A2[maxn];
bool vis[maxn];
void in(int x) {
  vis[x] = 1;
  printf("? %d\n", x);
  fflush(stdout);
  scanf("%d", &num[x]);
  for (int i = 1; i <= num[x]; i++) {
    scanf("%d", &ch[x][i]);
  }
}
int get(int x) {
  for (int i = 1; i <= num[x]; i++) {
    if (!vis[ch[x][i]]) {
      return ch[x][i];
    }
  }
  return ch[x][1];
}
int Solve() {
  memset(vis, 0, sizeof vis);
  scanf("%d", &h);
  int dep, x = 1;
  in(x);
  if (num[x] == 2) {
    return x;
  }
  if (num[x] == 1) {
    dep = 1;
  } else {
    int cnt1 = 0, cnt2 = 0;
    for (int v = get(x);; v = get(v)) {
      in(v);
      A1[++cnt1] = v;
      if (num[v] == 2) {
        return v;
      }
      if (num[v] == 1) {
        break;
      }
    }
    for (int v = get(x);; v = get(v)) {
      in(v);
      A2[++cnt2] = v;
      if (num[v] == 2) {
        return v;
      }
      if (num[v] == 1) {
        break;
      }
    }
    dep = (cnt1 + cnt2) / 2 + 1;
    if (cnt1 > cnt2) {
      x = A1[cnt1 - dep + 1];
    } else if (cnt1 < cnt2) {
      x = A2[cnt2 - dep + 1];
    }
  }
  for (int cnt = 0; dep < 4; cnt = 0) {
    for (int v = get(x);; v = get(v)) {
      in(v);
      A1[++cnt] = v;
      if (num[v] == 2) {
        return v;
      }
      if (num[v] == 1) {
        break;
      }
    }
    dep = (dep + cnt + 1) / 2, x = A1[cnt - dep + 1];
  }
  int a, b, c, d, e;
  if (dep < h) {
    x = get(x);
    in(x);
    if (num[x] == 2) {
      return x;
    }
  }
  if (dep < h - 1) {
    a = get(x);
    in(a);
    if (num[a] == 2) {
      return a;
    }
    b = get(x);
    in(b);
    if (num[b] == 2) {
      return b;
    }
  }
  if (dep < h - 2) {
    c = get(a);
    in(c);
    if (num[c] == 2) {
      return c;
    }
    d = get(a);
    in(d);
    if (num[d] == 2) {
      return d;
    }
    e = get(b);
    in(e);
    if (num[e] == 2) {
      return e;
    }
    return get(b);
  }
  return x;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("! %d\n", Solve());
    fflush(stdout);
  }
  return 0;
}
