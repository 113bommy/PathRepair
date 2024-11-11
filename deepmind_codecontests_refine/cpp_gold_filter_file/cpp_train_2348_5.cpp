#include <bits/stdc++.h>
using namespace std;
struct edg {
  bool tpe;
  int u, v;
  int gt00, gt01, gt10, gt11;
};
const int md = 1000000007;
inline void add(int &a, int b) {
  a += b;
  if (a >= md) a -= md;
}
inline int mul(int a, int b) { return 1ll * a * b % md; }
int mn0, mn1;
void updmn(int s0, int s1) {
  int n0 = mul(mn0, s0);
  add(n0, mul(mn1, s1));
  int n1 = mul(mn0, s1);
  add(n1, mul(mn1, s0));
  mn0 = n0;
  mn1 = n1;
}
void upd(int &a0, int &a1, int s0, int s1) {
  int n0 = mul(a0, s0);
  add(n0, mul(a1, s1));
  int n1 = mul(a0, s1);
  add(n1, mul(a1, s0));
  a0 = n0;
  a1 = n1;
}
bool vis[100010];
int deg[100010];
vector<edg> adj[100010];
int cnt[100010];
int cur[100010];
int dp[100010][2][2];
inline void cto(int i, int j) { memcpy(dp[j], dp[i], sizeof(dp[i])); }
void updsel(int ii, int &a0, int &a1, int cho) {
  int i = cur[ii];
  vis[i] = 1;
  if (cho) {
    int cnt = 0;
    for (int j = adj[i].size() - 1; ~j; --j) {
      if (!adj[i][j].tpe && adj[i][j].gt01) {
        ++cnt;
      }
    }
    if (cnt & 1) {
      swap(a0, a1);
    }
  } else {
    int cnt = 0;
    for (int j = adj[i].size() - 1; ~j; --j) {
      if (!adj[i][j].tpe && adj[i][j].gt00) {
        ++cnt;
      }
    }
    if (cnt & 1) {
      swap(a0, a1);
    }
  }
}
void solve_line(int n) {
  dp[1][0][1] = dp[1][1][1] = 0;
  dp[1][0][0] = dp[1][1][0] = 1;
  updsel(1, dp[1][0][0], dp[1][0][1], 0);
  updsel(1, dp[1][1][0], dp[1][1][1], 1);
  for (int i = 2; i <= n; ++i) {
    memset(dp[i], 0, sizeof(dp[i]));
    int _ = cur[i];
    int cnt;
    cnt = 0;
    for (int j = adj[_].size() - 1; ~j; --j) {
      if (adj[_][j].v == cur[i - 1]) {
        cnt += adj[_][j].gt00;
      }
    }
    if (cnt & 1) {
      add(dp[i][0][0], dp[i - 1][0][1]);
      add(dp[i][0][1], dp[i - 1][0][0]);
    } else {
      add(dp[i][0][0], dp[i - 1][0][0]);
      add(dp[i][0][1], dp[i - 1][0][1]);
    }
    cnt = 0;
    for (int j = adj[_].size() - 1; ~j; --j) {
      if (adj[_][j].v == cur[i - 1]) {
        cnt += adj[_][j].gt10;
      }
    }
    if (cnt & 1) {
      add(dp[i][1][0], dp[i - 1][0][1]);
      add(dp[i][1][1], dp[i - 1][0][0]);
    } else {
      add(dp[i][1][0], dp[i - 1][0][0]);
      add(dp[i][1][1], dp[i - 1][0][1]);
    }
    cnt = 0;
    for (int j = adj[_].size() - 1; ~j; --j) {
      if (adj[_][j].v == cur[i - 1]) {
        cnt += adj[_][j].gt01;
      }
    }
    if (cnt & 1) {
      add(dp[i][0][0], dp[i - 1][1][1]);
      add(dp[i][0][1], dp[i - 1][1][0]);
    } else {
      add(dp[i][0][0], dp[i - 1][1][0]);
      add(dp[i][0][1], dp[i - 1][1][1]);
    }
    cnt = 0;
    for (int j = adj[_].size() - 1; ~j; --j) {
      if (adj[_][j].v == cur[i - 1]) {
        cnt += adj[_][j].gt11;
      }
    }
    if (cnt & 1) {
      add(dp[i][1][0], dp[i - 1][1][1]);
      add(dp[i][1][1], dp[i - 1][1][0]);
    } else {
      add(dp[i][1][0], dp[i - 1][1][0]);
      add(dp[i][1][1], dp[i - 1][1][1]);
    }
    updsel(i, dp[i][0][0], dp[i][0][1], 0);
    updsel(i, dp[i][1][0], dp[i][1][1], 1);
  }
  updmn(dp[n][0][0] + dp[n][1][0], dp[n][0][1] + dp[n][1][1]);
}
void solve_circ(int n) {
  int c0 = 0, c1 = 0;
  dp[1][0][0] = 1;
  dp[1][0][1] = dp[1][1][0] = dp[1][1][1] = 0;
  for (int i = 2; i <= n; ++i) {
    memset(dp[i], 0, sizeof(dp[i]));
    int _ = cur[i];
    int cnt;
    cnt = 0;
    for (int j = adj[_].size() - 1; ~j; --j) {
      if (adj[_][j].v == cur[i - 1]) {
        cnt += adj[_][j].gt00;
      }
    }
    if (cnt & 1) {
      add(dp[i][0][0], dp[i - 1][0][1]);
      add(dp[i][0][1], dp[i - 1][0][0]);
    } else {
      add(dp[i][0][0], dp[i - 1][0][0]);
      add(dp[i][0][1], dp[i - 1][0][1]);
    }
    cnt = 0;
    for (int j = adj[_].size() - 1; ~j; --j) {
      if (adj[_][j].v == cur[i - 1]) {
        cnt += adj[_][j].gt10;
      }
    }
    if (cnt & 1) {
      add(dp[i][1][0], dp[i - 1][0][1]);
      add(dp[i][1][1], dp[i - 1][0][0]);
    } else {
      add(dp[i][1][0], dp[i - 1][0][0]);
      add(dp[i][1][1], dp[i - 1][0][1]);
    }
    cnt = 0;
    for (int j = adj[_].size() - 1; ~j; --j) {
      if (adj[_][j].v == cur[i - 1]) {
        cnt += adj[_][j].gt01;
      }
    }
    if (cnt & 1) {
      add(dp[i][0][0], dp[i - 1][1][1]);
      add(dp[i][0][1], dp[i - 1][1][0]);
    } else {
      add(dp[i][0][0], dp[i - 1][1][0]);
      add(dp[i][0][1], dp[i - 1][1][1]);
    }
    cnt = 0;
    for (int j = adj[_].size() - 1; ~j; --j) {
      if (adj[_][j].v == cur[i - 1]) {
        cnt += adj[_][j].gt11;
      }
    }
    if (cnt & 1) {
      add(dp[i][1][0], dp[i - 1][1][1]);
      add(dp[i][1][1], dp[i - 1][1][0]);
    } else {
      add(dp[i][1][0], dp[i - 1][1][0]);
      add(dp[i][1][1], dp[i - 1][1][1]);
    }
  }
  if (n != 2) {
    int t0 = 0, t1 = 0;
    for (int j = adj[cur[n]].size() - 1; ~j; --j) {
      if (adj[cur[n]][j].v == cur[1]) {
        t0 = 0, t1 = 0;
        if (adj[cur[n]][j].gt00) {
          add(t0, dp[n][0][1]);
          add(t1, dp[n][0][0]);
        } else {
          add(t0, dp[n][0][0]);
          add(t1, dp[n][0][1]);
        }
        if (adj[cur[n]][j].gt10) {
          add(t0, dp[n][1][1]);
          add(t1, dp[n][1][0]);
        } else {
          add(t0, dp[n][1][0]);
          add(t1, dp[n][1][1]);
        }
        break;
      }
    }
    add(c0, t0);
    add(c1, t1);
  } else {
    add(c0, dp[n][0][0]);
    add(c0, dp[n][1][0]);
    add(c1, dp[n][0][1]);
    add(c1, dp[n][1][1]);
  }
  dp[1][1][0] = 1;
  dp[1][0][0] = dp[1][0][1] = dp[1][1][1] = 0;
  for (int i = 2; i <= n; ++i) {
    memset(dp[i], 0, sizeof(dp[i]));
    int _ = cur[i];
    int cnt;
    cnt = 0;
    for (int j = adj[_].size() - 1; ~j; --j) {
      if (adj[_][j].v == cur[i - 1]) {
        cnt += adj[_][j].gt00;
      }
    }
    if (cnt & 1) {
      add(dp[i][0][0], dp[i - 1][0][1]);
      add(dp[i][0][1], dp[i - 1][0][0]);
    } else {
      add(dp[i][0][0], dp[i - 1][0][0]);
      add(dp[i][0][1], dp[i - 1][0][1]);
    }
    cnt = 0;
    for (int j = adj[_].size() - 1; ~j; --j) {
      if (adj[_][j].v == cur[i - 1]) {
        cnt += adj[_][j].gt10;
      }
    }
    if (cnt & 1) {
      add(dp[i][1][0], dp[i - 1][0][1]);
      add(dp[i][1][1], dp[i - 1][0][0]);
    } else {
      add(dp[i][1][0], dp[i - 1][0][0]);
      add(dp[i][1][1], dp[i - 1][0][1]);
    }
    cnt = 0;
    for (int j = adj[_].size() - 1; ~j; --j) {
      if (adj[_][j].v == cur[i - 1]) {
        cnt += adj[_][j].gt01;
      }
    }
    if (cnt & 1) {
      add(dp[i][0][0], dp[i - 1][1][1]);
      add(dp[i][0][1], dp[i - 1][1][0]);
    } else {
      add(dp[i][0][0], dp[i - 1][1][0]);
      add(dp[i][0][1], dp[i - 1][1][1]);
    }
    cnt = 0;
    for (int j = adj[_].size() - 1; ~j; --j) {
      if (adj[_][j].v == cur[i - 1]) {
        cnt += adj[_][j].gt11;
      }
    }
    if (cnt & 1) {
      add(dp[i][1][0], dp[i - 1][1][1]);
      add(dp[i][1][1], dp[i - 1][1][0]);
    } else {
      add(dp[i][1][0], dp[i - 1][1][0]);
      add(dp[i][1][1], dp[i - 1][1][1]);
    }
  }
  if (n != 2) {
    int t0 = 0, t1 = 0;
    for (int j = adj[cur[n]].size() - 1; ~j; --j) {
      if (adj[cur[n]][j].v == cur[1]) {
        t0 = 0, t1 = 0;
        if (adj[cur[n]][j].gt01) {
          add(t0, dp[n][0][1]);
          add(t1, dp[n][0][0]);
        } else {
          add(t0, dp[n][0][0]);
          add(t1, dp[n][0][1]);
        }
        if (adj[cur[n]][j].gt11) {
          add(t0, dp[n][1][1]);
          add(t1, dp[n][1][0]);
        } else {
          add(t0, dp[n][1][0]);
          add(t1, dp[n][1][1]);
        }
        break;
      }
    }
    add(c0, t0);
    add(c1, t1);
  } else {
    add(c0, dp[n][0][0]);
    add(c0, dp[n][1][0]);
    add(c1, dp[n][0][1]);
    add(c1, dp[n][1][1]);
  }
  updmn(c0, c1);
}
int main(void) {
  mn0 = 1;
  int n, m;
  scanf("%d%d", &m, &n);
  for (int i = 1; i <= m; ++i) {
    int k, u, v;
    bool ut = 0, vt = 0;
    edg t;
    scanf("%d", &k);
    if (k & 1) {
      scanf("%d", &u);
      if (u < 0) ut = 1, u = -u;
      t.tpe = 0;
      t.u = u;
      if (ut) {
        t.gt00 = 1;
        t.gt01 = 0;
        t.gt10 = t.gt11 = 0;
      } else {
        t.gt00 = 0;
        t.gt01 = 1;
        t.gt10 = t.gt11 = 0;
      }
      adj[u].push_back(t);
    } else {
      scanf("%d%d", &u, &v);
      if (u < 0) ut = 1, u = -u;
      if (v < 0) vt = 1, v = -v;
      t.u = u;
      t.v = v;
      if (u == v) {
        t.tpe = 0;
        if (ut) {
          if (vt) {
            t.gt00 = 1;
            t.gt01 = t.gt10 = t.gt11 = 0;
          } else {
            t.gt00 = t.gt01 = 1;
            t.gt10 = t.gt11 = 0;
          }
        } else {
          if (vt) {
            t.gt00 = t.gt01 = 1;
            t.gt10 = t.gt11 = 0;
          } else {
            t.gt01 = 1;
            t.gt00 = t.gt10 = t.gt11 = 0;
          }
        }
        adj[u].push_back(t);
      } else {
        ++deg[u];
        ++deg[v];
        t.tpe = 1;
        if (ut) {
          if (vt) {
            t.gt00 = t.gt01 = t.gt10 = 1;
            t.gt11 = 0;
          } else {
            t.gt00 = t.gt01 = t.gt11 = 1;
            t.gt10 = 0;
          }
        } else {
          if (vt) {
            t.gt00 = t.gt10 = t.gt11 = 1;
            t.gt01 = 0;
          } else {
            t.gt01 = t.gt10 = t.gt11 = 1;
            t.gt00 = 0;
          }
        }
        adj[u].push_back(t);
        swap(t.u, t.v);
        swap(t.gt01, t.gt10);
        adj[v].push_back(t);
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (!deg[i]) {
      vis[i] = 1;
      int fn0 = 0, fn1 = 0;
      int cnt = 0;
      for (int j = adj[i].size() - 1; ~j; --j) {
        if (adj[i][j].gt00) {
          ++cnt;
        }
      }
      if (cnt & 1)
        ++fn1;
      else
        ++fn0;
      cnt = 0;
      for (int j = adj[i].size() - 1; ~j; --j) {
        if (adj[i][j].gt01) {
          ++cnt;
        }
      }
      if (cnt & 1)
        ++fn1;
      else
        ++fn0;
      updmn(fn0, fn1);
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (!vis[i] && (deg[i] & 1)) {
      int cnt = 1;
      queue<int> q;
      q.push(i);
      cur[1] = i;
      vis[i] = 1;
      while (!q.empty()) {
        int id = q.front();
        q.pop();
        for (int j = adj[id].size() - 1; ~j; --j) {
          int nxt = adj[id][j].v;
          if (adj[id][j].tpe && !vis[nxt]) {
            vis[nxt] = 1;
            cur[++cnt] = nxt;
            q.push(nxt);
            break;
          }
        }
      }
      solve_line(cnt);
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) {
      int cnt = 1;
      queue<int> q;
      q.push(i);
      cur[1] = i;
      vis[i] = 1;
      while (!q.empty()) {
        int id = q.front();
        q.pop();
        for (int j = adj[id].size() - 1; ~j; --j) {
          int nxt = adj[id][j].v;
          if (!vis[nxt]) {
            vis[nxt] = 1;
            cur[++cnt] = nxt;
            q.push(nxt);
            break;
          }
        }
      }
      solve_circ(cnt);
    }
  }
  printf("%d", mn1);
  return 0;
}
