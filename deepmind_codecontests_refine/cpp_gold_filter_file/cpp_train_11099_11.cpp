#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
const long long inf = 1e15;
int n, m, k;
struct flight {
  int pos, cost;
};
long long g1[maxn], g2[maxn], sum1[maxn], sum2[maxn];
vector<flight> G1[maxn], G2[maxn];
int f[maxn];
template <class T>
void read(T &x) {
  x = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
}
int main() {
  int d, u, v, c, Maxday = 0;
  read(n), read(m), read(k);
  for (int i = (1); i <= (int)(m); ++i) {
    read(d), read(u), read(v), read(c);
    if (v == 0)
      G1[d].push_back((flight){u, c});
    else
      G2[d].push_back((flight){v, c});
    Maxday = max(d, Maxday);
  }
  sum1[0] = sum2[Maxday + 1] = inf;
  int cnt = 0;
  long long res = 0;
  for (int i = (1); i <= (int)(Maxday); ++i) {
    if (!G1[i].size())
      sum1[i] = sum1[i - 1];
    else {
      for (int j = (0); j <= (int)(G1[i].size() - 1); ++j) {
        u = G1[i][j].pos, c = G1[i][j].cost;
        if (cnt < n) {
          if (g1[u]) {
            if (c < g1[u]) res += c - g1[u], g1[u] = c;
          } else
            g1[u] = c, res += c, ++cnt;
          if (cnt == n)
            sum1[i] = res;
          else
            sum1[i] = inf;
        } else {
          sum1[i] = res;
          if (c < g1[u]) sum1[i] += c - g1[u], g1[u] = c;
          res = sum1[i];
        }
      }
    }
  }
  cnt = 0, res = 0;
  for (int i = (Maxday); i >= (int)(1); --i) {
    if (!G2[i].size())
      sum2[i] = sum2[i + 1];
    else {
      for (int j = (0); j <= (int)(G2[i].size() - 1); ++j) {
        u = G2[i][j].pos, c = G2[i][j].cost;
        if (cnt < n) {
          if (g2[u]) {
            if (c < g2[u]) res += c - g2[u], g2[u] = c;
          } else
            g2[u] = c, res += c, ++cnt;
          if (cnt == n)
            sum2[i] = res;
          else
            sum2[i] = inf;
        } else {
          sum2[i] = res;
          if (c < g2[u]) sum2[i] += c - g2[u], g2[u] = c;
          res = sum2[i];
        }
      }
    }
  }
  long long ans = inf;
  for (int i = (1); i <= (int)(Maxday - k - 1); ++i)
    ans = min(ans, sum1[i] + sum2[i + k + 1]);
  cout << (ans >= inf ? -1 : ans) << endl;
  return 0;
}
