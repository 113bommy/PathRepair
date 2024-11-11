#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3fffffff;
const int SINF = 0x7fffffff;
const long long LINF = 0x3fffffffffffffff;
const long long SLINF = 0x7fffffffffffffff;
const int MAXN = 1000007;
struct sT {
  sT() : b(0), d(0), k(0) {}
  sT(int _b, int _d, int _k) : b(_b), d(_d), k(_k) {}
  int b, d, k;
};
int n;
char ss[MAXN], st[MAXN], s[MAXN];
int dp[MAXN], pdp[MAXN], gpl[MAXN], pgpl[MAXN];
vector<sT> g, g1;
void init();
void input();
void work();
int main() {
  init();
  input();
  work();
}
void init() { ios::sync_with_stdio(false); }
void input() { scanf("%s%s", ss, st); }
void work() {
  int tlen = strlen(ss);
  for (int i = 0; i < tlen; ++i) s[++n] = ss[i], s[++n] = st[i];
  int pre, size, cv, np;
  for (int i = 1; i <= n; ++i) {
    g1.clear();
    pre = -i;
    for (auto x : g) {
      if (x.b > 1 && s[i] == s[x.b - 1]) {
        if (x.b - 1 - pre == x.d)
          g1.push_back(sT(x.b - 1, x.d, x.k));
        else {
          g1.push_back(sT(x.b - 1, x.b - 1 - pre, 1));
          if (x.k > 1) g1.push_back(sT(x.b + x.d - 1, x.d, x.k - 1));
        }
        pre = g1.back().b + g1.back().d * (g1.back().k - 1);
      }
    }
    dp[i] = INF;
    pdp[i] = -1;
    if (i > 1 && s[i] == s[i - 1]) {
      dp[i] = dp[i - 2], pdp[i] = i - 2;
      g1.push_back(sT(i - 1, i - 1 - pre, 1));
    }
    g.clear();
    if (!g1.empty()) {
      g.push_back(g1.front());
      size = g1.size();
      for (int j = 1; j < size; ++j) {
        if (g.back().d == g1[j].d)
          g.back().k += g1[j].k;
        else
          g.push_back(g1[j]);
      }
    }
    for (auto x : g) {
      np = x.b + x.d * (x.k - 1) - 1;
      cv = dp[np] + 1;
      if (x.k > 1) {
        if (gpl[x.b - x.d] < cv) {
          cv = gpl[x.b - x.d];
          np = pgpl[x.b - x.d];
        }
      }
      if (x.b - x.d >= 0) gpl[x.b - x.d] = cv, pgpl[x.b - x.d] = np;
      if (cv < dp[i]) dp[i] = cv, pdp[i] = np;
    }
  }
  if (dp[n] == INF) {
    printf("-1\n");
    return;
  }
  printf("%d\n", dp[n]);
  int cur = n;
  while (cur) {
    if (dp[pdp[cur]] ^ dp[cur])
      printf("%d %d\n", (pdp[cur] + 2) >> 1, (cur + 1) >> 1);
    cur = pdp[cur];
  }
}
