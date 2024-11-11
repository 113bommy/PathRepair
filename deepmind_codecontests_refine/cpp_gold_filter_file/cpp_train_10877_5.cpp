#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x) {
  x = 0;
  char ch = getchar();
  int fh = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') fh = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  x *= fh;
}
struct shj {
  int we, l, r, fh;
} t[100010 * 6];
struct pte {
  int l0, r0, l1, r1;
} g[100010];
struct teache {
  int l, r;
} v[100010];
multiset<int> nl, nr;
int T1, T2, m, n, x, y, b1[100010], b2[100010], num, nt, anx = -1, any = -1,
                                                         no[100010];
bool ans = 1, v1[100010];
vector<int> e[100010];
bool c1(const shj &a, const shj &b) {
  if (a.we != b.we) return a.we < b.we;
  return a.fh > b.fh;
}
void dfs(int no, int bi) {
  b1[no] = bi;
  b2[no] = num;
  v1[no] = 0;
  for (unsigned i = 0; i < e[no].size(); i++) {
    if (v1[e[no][i]])
      dfs(e[no][i], bi ^ 1);
    else if (b1[no] == b1[e[no][i]])
      ans = 0;
  }
}
int main() {
  read(T1);
  read(T2);
  read(n);
  read(m);
  for (int i = 1; i <= n; i++) {
    read(v[i].l);
    read(v[i].r);
  }
  for (int i = 1; i <= m; i++) {
    read(x);
    read(y);
    e[x].push_back(y);
    e[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) v1[i] = 1;
  for (int i = 1; i <= n; i++)
    if (v1[i]) {
      num++;
      dfs(i, 0);
    }
  if (!ans) {
    puts("IMPOSSIBLE");
    return 0;
  }
  for (int i = 1; i <= num; i++) {
    g[i].l0 = g[i].l1 = 0;
    g[i].r0 = g[i].r1 = 1e9;
  }
  for (int i = 1; i <= n; i++) {
    if (b1[i] == 0) {
      g[b2[i]].l0 = max(g[b2[i]].l0, v[i].l);
      g[b2[i]].r0 = min(g[b2[i]].r0, v[i].r);
    } else {
      g[b2[i]].l1 = max(g[b2[i]].l1, v[i].l);
      g[b2[i]].r1 = min(g[b2[i]].r1, v[i].r);
    }
  }
  for (int i = 1; i <= num; i++)
    if (g[i].l0 > g[i].r0 || g[i].l1 > g[i].r1) {
      puts("IMPOSSIBLE");
      return 0;
    }
  for (int i = 1; i <= num; i++) {
    pte no = g[i];
    if (no.l0 > no.l1) {
      swap(no.l0, no.l1);
      swap(no.r0, no.r1);
    }
    t[++nt] = (shj){no.l0, no.l1, no.r1, 1};
    t[++nt] = (shj){no.l1, no.l1, no.r1, -1};
    if (no.r0 >= no.r1) {
      t[++nt] = (shj){no.l1, no.l0, no.r0, 1};
      t[++nt] = (shj){no.r1 + 1, no.l0, no.r0, -1};
      t[++nt] = (shj){no.r1 + 1, no.l1, no.r1, 1};
      t[++nt] = (shj){no.r0 + 1, no.l1, no.r1, -1};
    } else {
      t[++nt] = (shj){no.l1, no.l0, no.r1, 1};
      t[++nt] = (shj){no.r0 + 1, no.l0, no.r1, -1};
      t[++nt] = (shj){no.r0 + 1, no.l0, no.r0, 1};
      t[++nt] = (shj){no.r1 + 1, no.l0, no.r0, -1};
    }
  }
  sort(t + 1, t + nt + 1, c1);
  for (int l = 1, r = 0; l <= nt; l = r + 1) {
    while (t[r + 1].we == t[l].we && r + 1 <= nt) {
      r++;
      if (t[r].fh == 1) {
        nl.insert(t[r].l);
        nr.insert(t[r].r);
      } else {
        auto i = nl.find(t[r].l);
        nl.erase(i);
        auto j = nr.find(t[r].r);
        nr.erase(j);
      }
    }
    if (nl.size() == num) {
      auto i = nl.end();
      i--;
      int al = (*i), ar = (*(nr.begin())), sl = t[l].we, sr = t[r + 1].we - 1;
      if (al + sl > T2 || ar + sr < T1 || al > ar || sl > sr) continue;
      if (al + sl >= T1) {
        anx = sl;
        any = al;
      } else {
        if (ar + sr <= T2) {
          anx = sr;
          any = ar;
        } else {
          if (al + sr > T2) {
            anx = T1 - al;
            any = al;
          } else {
            anx = sr;
            any = T2 - sr;
          }
        }
      }
    }
  }
  if (anx == -1 && any == -1) {
    puts("IMPOSSIBLE");
    return 0;
  }
  puts("POSSIBLE");
  printf("%d %d\n", anx, any);
  for (int i = 1; i <= num; i++)
    if (anx <= g[i].r0 && anx >= g[i].l0 && any <= g[i].r1 && any >= g[i].l1)
      no[i] = 0;
    else
      no[i] = 1;
  for (int i = 1; i <= n; i++)
    if (no[b2[i]] == b1[i])
      putchar('1');
    else
      putchar('2');
  return 0;
}
