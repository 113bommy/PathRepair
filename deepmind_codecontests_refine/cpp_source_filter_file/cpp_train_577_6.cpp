#include <bits/stdc++.h>
const int N = 305;
int T, h, cnt, num[N], f[N], a[N], sa, b[N], sb;
std::vector<int> G[N];
void ask(int x) {
  if (cnt == 16) return;
  ++cnt;
  if (!f[x]) {
    f[x] = 1;
    printf("? %d\n", x);
    fflush(stdout);
    scanf("%d", &num[x]);
    for (int i = 1, k; i <= num[x]; i++) {
      scanf("%d", &k);
      G[x].push_back(k);
    }
  }
}
int find(int x) {
  for (int p : G[x])
    if (!f[p]) return p;
  return G[x][0];
}
void report(int v) {
  printf("! %d\n", v);
  fflush(stdout);
}
int main() {
  scanf("%d", &T);
  while (T--) {
    cnt = 0;
    scanf("%d", &h);
    for (int i = 1; i < 1 << h; i++) G[i].clear(), f[i] = 0;
    int v = 1, dep;
    ask(v);
    if (num[v] == 2) {
      report(v);
      continue;
    }
    if (num[v] == 1) {
      dep = 1;
      while (dep < 4 && dep < h) {
        sa = 0;
        int o = v;
        while (1) {
          int nxt = find(o);
          ask(nxt);
          a[++sa] = nxt;
          o = nxt;
          if (num[o] == 1) break;
        }
        for (int i = 1; i <= sa; i++)
          if (sa - i == i - 1 + dep) {
            v = a[i];
            dep = sa - i + 1;
            break;
          }
      }
      if (num[v] == 2) {
        report(v);
        continue;
      }
      int p, q, r;
      if (dep == h - 1) {
        p = find(v);
        ask(p);
        if (num[p] == 2) {
          report(p);
          continue;
        }
      }
      if (dep == h - 2) {
        p = find(v);
        ask(p);
        q = find(p);
        ask(q);
        if (num[q] == 2) {
          report(q);
          continue;
        }
        q = find(p);
        ask(q);
        if (num[q] == 2) {
          report(q);
          continue;
        }
      }
      if (dep == h - 3) {
        p = find(v);
        ask(p);
        for (int i = 0; i < 2; i++) {
          q = find(p);
          ask(q);
          for (int j = 0; j < 2; j++) {
            r = find(q);
            ask(r);
            if (num[r] == 2) goto ouu;
          }
        }
      ouu:
        report(r);
        continue;
      }
    }
    if (num[v] == 3) {
      int x, y;
      x = y = v;
      sa = sb = 0;
      while (1) {
        int nxt = find(x);
        a[++sa] = nxt;
        ask(nxt);
        x = nxt;
        if (num[nxt] == 1) break;
      }
      while (1) {
        int nxt = find(y);
        b[++sb] = nxt;
        ask(nxt);
        y = nxt;
        if (num[nxt] == 1) break;
      }
      if (sa == sb) {
        dep = sa + 1;
      }
      if (sa > sb) {
        for (int i = 1; i <= sa; i++)
          if (sa - i == i + sb) {
            v = a[i];
            dep = sa - i + 1;
            break;
          }
      }
      if (sa < sb) {
        for (int i = 1; i <= sb; i++)
          if (sb - i == i + sa) {
            v = b[i];
            dep = sb - i + 1;
            break;
          }
      }
      while (dep < h - 3) {
        sa = 0;
        int o = v;
        while (1) {
          int nxt = find(o);
          ask(nxt);
          a[++sa] = nxt;
          o = nxt;
          if (num[o] == 1) break;
        }
        for (int i = 1; i <= sa; i++)
          if (sa - i == i - 1 + dep) {
            v = a[i];
            dep = sa - i;
            break;
          }
      }
      if (num[v] == 2) {
        report(v);
        continue;
      }
      int p, q, r;
      if (dep == h - 1) {
        p = find(v);
        ask(p);
        if (num[p] == 2) {
          report(p);
          continue;
        }
      }
      if (dep == h - 2) {
        p = find(v);
        ask(p);
        q = find(p);
        ask(q);
        if (num[q] == 2) {
          report(q);
          continue;
        }
        q = find(p);
        ask(q);
        if (num[q] == 2) {
          report(q);
          continue;
        }
      }
      if (dep == h - 3) {
        p = find(v);
        ask(p);
        for (int i = 0; i < 2; i++) {
          q = find(p);
          ask(q);
          for (int j = 0; j < 2; j++) {
            r = find(q);
            ask(r);
            if (num[r] == 2) goto eaa;
          }
        }
      eaa:
        report(r);
        continue;
      }
    }
  }
  return 0;
}
