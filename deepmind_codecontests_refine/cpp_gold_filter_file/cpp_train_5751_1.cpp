#include <bits/stdc++.h>
using namespace std;
inline char gc() {
  static char buf[100000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline long long read() {
  long long x = 0;
  char ch = getchar();
  bool positive = 1;
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') positive = 0;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  return positive ? x : -x;
}
inline void write(long long a) {
  if (a < 0) {
    a = -a;
    putchar('-');
  }
  if (a >= 10) write(a / 10);
  putchar('0' + a % 10);
}
inline void writeln(long long a) {
  write(a);
  puts("");
}
inline void wri(long long a) {
  write(a);
  putchar(' ');
}
inline unsigned long long rnd() {
  return ((unsigned long long)rand() << 30 ^ rand()) << 4 | rand() % 4;
}
const int N = 105, mod = 998244353;
long long f[N], dp[N], DP[N << 1], val[N][N];
vector<int> v[N], way[N][N], d[N];
pair<int, int> a[N];
int n, rt, e[N][N], fir[N][N], lst[N][N], cover[N][N];
void dfs_way(int p, int fa) {
  way[rt][p] = way[rt][fa];
  way[rt][p].push_back(p);
  for (auto i : v[p])
    if (i != fa) dfs_way(i, p);
}
long long mul(pair<int, int> a, pair<int, int> b) {
  return (long long)a.first * b.second - (long long)a.second * b.first;
}
pair<int, int> operator-(pair<int, int> a, pair<int, int> b) {
  return make_pair(a.first - b.first, a.second - b.second);
}
bool cmp(int x, int y) {
  return a[x].second == a[y].second ? a[x].first < a[y].first
                                    : a[x].second < a[y].second;
}
int half(pair<int, int> x) {
  return x.second < 0 || (x.second == 0 && x.first < 0);
}
bool cnm(pair<int, int> x, pair<int, int> y) {
  pair<int, int> A = a[x.second] - a[x.first], B = a[y.second] - a[y.first];
  int X = half(A), Y = half(B);
  return X == Y ? mul(A, B) > 0 : X < Y;
}
void dfs(int p, int fa) {
  for (auto it = v[p].begin(); it != v[p].end(); it++)
    if (*it == fa) {
      v[p].erase(it);
      break;
    }
  d[p].push_back(p);
  for (auto i : v[p]) {
    dfs(i, p);
    for (auto j : d[i]) d[p].push_back(j);
  }
  f[p] = 1;
  for (auto i : v[p]) f[p] = f[p] * dp[i] % mod;
  dp[p] = f[p];
  for (auto i : v[p]) {
    long long zs = f[i];
    for (auto j : v[p])
      if (i != j) zs = zs * dp[j] % mod;
    dp[p] = (dp[p] + zs) % mod;
  }
  int k = 0;
  memset((e), 0, sizeof(e));
  for (auto i : d[p])
    for (auto j : v[i]) {
      e[i][j] = ++k;
      e[j][i] = ++k;
    }
  vector<pair<int, int> > al;
  sort(d[p].begin(), d[p].end(), cmp);
  int m = d[p].size();
  for (auto i : d[p])
    for (auto j : d[p])
      if (way[i][j].size() >= 3 && mul(a[j] - a[i], a[p] - a[i]) >= 0) {
        al.push_back(make_pair(i, j));
        int sz = way[i][j].size();
        fir[i][j] = e[way[i][j][0]][way[i][j][1]];
        lst[i][j] = e[way[i][j].back()][way[i][j][sz - 2]];
        cover[i][j] = 0;
        val[i][j] = 1;
        for (int o = (int)(0); o <= (int)(sz - 1); o++) {
          int x = o ? way[i][j][o - 1] : -1,
              y = o <= sz - 2 ? way[i][j][o + 1] : -1, dq = way[i][j][o];
          for (auto son : v[dq])
            if (son != x && son != y) {
              if (x < 0) {
                if (mul(a[y] - a[dq], a[son] - a[dq]) > 0) continue;
              } else if (y < 0) {
                if (mul(a[son] - a[x], a[dq] - a[x]) < 0) continue;
              } else {
                int A = mul(a[y] - a[dq], a[son] - a[dq]) > 0,
                    B = mul(a[son] - a[x], a[dq] - a[x]) < 0;
                if (mul(a[dq] - a[x], a[y] - a[x]) > 0) {
                  if (A && B) continue;
                } else {
                  if (A || B) continue;
                }
              }
              val[i][j] = val[i][j] * dp[son] % mod;
            }
          cover[i][j] |= dq == p;
        }
      }
  sort(al.begin(), al.end(), cnm);
  for (int i = (int)(0); i <= (int)(m - 1); i++)
    for (int j = (int)(i + 1); j <= (int)(m - 1); j++)
      if (e[d[p][i]][d[p][j]]) {
        for (int ban = -1; ban <= 1; ban += 2) {
          memset((DP), 0, sizeof(DP));
          DP[e[d[p][i]][d[p][j]]] = 1;
          for (auto o : al) {
            if (ban == -1 && cover[o.first][o.second]) continue;
            int S = fir[o.first][o.second], T = lst[o.first][o.second];
            DP[T] = (DP[T] + DP[S] * val[o.first][o.second]) % mod;
          }
          DP[e[d[p][i]][d[p][j]]] += mod - 1;
          dp[p] += ban * DP[e[d[p][i]][d[p][j]]];
        }
      }
  dp[p] = (dp[p] % mod + mod) % mod;
}
int main() {
  n = read();
  for (int i = (int)(1); i <= (int)(n); i++) {
    a[i].first = read();
    a[i].second = read();
  }
  for (int i = (int)(1); i <= (int)(n - 1); i++) {
    int s = read(), t = read();
    v[s].push_back(t);
    v[t].push_back(s);
  }
  for (int i = (int)(1); i <= (int)(n); i++) {
    rt = i;
    dfs_way(i, 0);
    for (int j = (int)(1); j <= (int)(n); j++) {
      for (auto k : way[i][j])
        if (mul(a[j] - a[i], a[k] - a[i]) < 0) {
          way[i][j].clear();
          break;
        }
    }
  }
  dfs(1, 0);
  cout << dp[1] << endl;
}
