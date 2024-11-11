#include <bits/stdc++.h>
using namespace std;
const int maxn = 2E5 + 5;
const long long mo = 1000000007;
int n, Ans, O, Max, cnt, tot, Cnt, phi[maxn], A[maxn], B[maxn], Fac[maxn],
    pri[maxn], inq[maxn], dis[maxn], Inv[maxn], siz[maxn], sumphi[maxn],
    vis[maxn];
bool not_pri[maxn], Huge[maxn];
queue<int> Q;
stack<int> stk;
vector<pair<int, int> > c[maxn];
vector<int> v[maxn], d[maxn];
inline int getint() {
  char ch = getchar();
  int ret = 0;
  while (ch < '0' || '9' < ch) ch = getchar();
  while ('0' <= ch && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
  return ret;
}
int ksm(int x, int y) {
  int ret = 1;
  for (; y; y >>= 1) {
    if (y & 1) ret = (1LL * (ret) * (x) % mo);
    x = (1LL * (x) * (x) % mo);
  }
  return ret;
}
inline void Insert(int x) {
  int y = A[x];
  for (int i = 0; i < d[y].size(); i++) {
    int now = d[y][i];
    sumphi[now] =
        ((sumphi[now]) + (phi[y]) < mo ? (sumphi[now]) + (phi[y])
                                       : (sumphi[now]) + (phi[y]) - mo);
    if (vis[now] != cnt) vis[now] = cnt, stk.push(now);
  }
}
inline void Clear() {
  while (!stk.empty()) sumphi[stk.top()] = 0, stk.pop();
}
inline void Dfs2(int x, int tot, int from) {
  int ma = 0;
  siz[x] = 1;
  for (int i = 0; i < v[x].size(); i++) {
    int to = v[x][i];
    if (to == from || Huge[to]) continue;
    Dfs2(to, tot, x);
    siz[x] += siz[to];
    ma = ((ma) > (siz[to]) ? (ma) : (siz[to]));
  }
  ma = ((ma) > (tot - siz[x]) ? (ma) : (tot - siz[x]));
  if (ma < Max) Max = ma, O = x;
}
inline void BFS1(int x) {
  dis[x] = 1;
  inq[x] = ++Cnt;
  Q.push(x);
  while (!Q.empty()) {
    int k = Q.front(), sum = 0, y = A[k];
    Q.pop();
    for (int i = 0; i < d[y].size(); i++)
      sum = ((sum) + ((1LL * (c[y][i].second) * (sumphi[d[y][i]]) % mo)) < mo
                 ? (sum) + ((1LL * (c[y][i].second) * (sumphi[d[y][i]]) % mo))
                 : (sum) + ((1LL * (c[y][i].second) * (sumphi[d[y][i]]) % mo)) -
                       mo);
    Ans =
        ((Ans) + ((1LL * (sum) * ((1LL * (phi[y]) * (dis[k]) % mo)) % mo)) < mo
             ? (Ans) + ((1LL * (sum) * ((1LL * (phi[y]) * (dis[k]) % mo)) % mo))
             : (Ans) +
                   ((1LL * (sum) * ((1LL * (phi[y]) * (dis[k]) % mo)) % mo)) -
                   mo);
    for (int i = 0; i < v[k].size(); i++) {
      int to = v[k][i];
      if (inq[to] == Cnt || Huge[to]) continue;
      inq[to] = Cnt;
      dis[to] = dis[k] + 1;
      Q.push(to);
    }
  }
}
inline int BFS2(int x) {
  int ret = 0;
  Q.push(x);
  inq[x] = ++Cnt;
  while (!Q.empty()) {
    int k = Q.front();
    Q.pop();
    ++ret;
    Insert(k);
    for (int i = 0; i < v[k].size(); i++) {
      int to = v[k][i];
      if (inq[to] == Cnt || Huge[to]) continue;
      inq[to] = Cnt;
      Q.push(to);
    }
  }
  return ret;
}
inline void Dfs1(int x, int tot) {
  Max = maxn;
  Dfs2(x, tot, 0);
  int o = O;
  Huge[o] = 1;
  ++cnt;
  Insert(o);
  for (int i = 0; i < v[o].size(); i++) {
    int to = v[o][i];
    if (Huge[to]) continue;
    BFS1(to);
    BFS2(to);
  }
  Clear();
  ++cnt;
  for (int i = v[o].size() - 1; i >= 0; i--) {
    int to = v[o][i];
    if (Huge[to]) continue;
    BFS1(to);
    siz[to] = BFS2(to);
  }
  Clear();
  for (int i = 0; i < v[o].size(); i++) {
    int to = v[o][i];
    if (Huge[to]) continue;
    Dfs1(to, siz[to]);
  }
}
void Pre_Work() {
  n = getint();
  Fac[0] = 1;
  for (int i = 1; i <= n; i++) Fac[i] = (1LL * (Fac[i - 1]) * (i) % mo);
  Inv[n] = ksm(Fac[n], mo - 2);
  for (int i = n - 1; i; i--) Inv[i] = (1LL * (Inv[i + 1]) * (i + 1) % mo);
  for (int i = n; i; i--) Inv[i] = (1LL * (Inv[i]) * (Fac[i - 1]) % mo);
  for (int i = 1; i <= n; i++) A[i] = getint();
  for (int i = 1; i < n; i++) {
    int x = getint(), y = getint();
    v[x].push_back(y);
    v[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) d[i].push_back(1);
  for (int i = 2; i <= n; i++)
    for (int j = i; j <= n; j += i) {
      d[j].push_back(i);
      if (!B[j]) B[j] = i;
    }
  c[1].push_back((make_pair((1), (1))));
  for (int i = 2; i <= n; i++) {
    int tmp = 0, q = i, p1 = 0, p2 = 0, p3 = 0;
    while (q % B[i] == 0) ++tmp, q /= B[i];
    for (int j = 0; j < d[i].size(); j++) {
      int z = d[i][j];
      if (z % B[i] != 0) {
        if (q % z != 0)
          c[i].push_back((make_pair((z), (0))));
        else {
          while (d[q][p1] != z) ++p1;
          c[i].push_back((make_pair((z), (c[q][p1].second))));
        }
      } else {
        pair<int, int> tmp = (make_pair((z), (0)));
        int now = z / B[i];
        if (q % z == 0) {
          while (d[q][p2] != z) ++p2;
          tmp.second = c[q][p2].second;
        }
        if (q % now == 0) {
          while (d[q][p3] != now) ++p3;
          tmp.second =
              ((tmp.second) +
                           ((1LL * (Inv[B[i] - 1]) * (c[q][p3].second) % mo)) <
                       mo
                   ? (tmp.second) +
                         ((1LL * (Inv[B[i] - 1]) * (c[q][p3].second) % mo))
                   : (tmp.second) +
                         ((1LL * (Inv[B[i] - 1]) * (c[q][p3].second) % mo)) -
                         mo);
        }
        c[i].push_back(tmp);
      }
    }
  }
  phi[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!not_pri[i]) pri[++tot] = i, phi[i] = i - 1;
    for (int j = 1; j <= tot; j++) {
      int Nex = i * pri[j];
      if (Nex > n) break;
      not_pri[Nex] = 1;
      if (i % pri[j] == 0) {
        phi[Nex] = phi[i] * pri[j];
        break;
      }
      phi[Nex] = phi[i] * (pri[j] - 1);
    }
  }
}
int main() {
  Pre_Work();
  Dfs1(1, n);
  cout << (1LL * ((1LL * (2) * (Ans) % mo)) *
           ((1LL * (Inv[n]) * (Inv[n - 1]) % mo)) % mo)
       << endl;
  return 0;
}
