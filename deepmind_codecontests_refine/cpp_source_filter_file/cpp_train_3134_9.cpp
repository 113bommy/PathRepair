#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int M = 5.1e6 + 10;
const int Q = 1.2e6;
bool ist[M];
int pri[2 * N], mind[M], pcnt;
void seive() {
  mind[1] = 1;
  for (int i = 2, s; i < M; i++) {
    if (!ist[i]) {
      pri[++pcnt] = i;
      mind[i] = i;
    }
    for (int j = 1; j <= pcnt && (s = pri[j] * i) < M; j++) {
      ist[s] = true;
      mind[s] = pri[j];
      if (i % pri[j] == 0) break;
    }
  }
}
vector<int> divsor[N];
vector<pair<int, int> > query[N];
int n, q;
int a[N], ans[Q];
void init() {
  seive();
  for (int i = 1; i <= n; i++) {
    int cur = a[i], res = 1;
    while (cur != 1) {
      int now = mind[cur], t = 0;
      while (mind[cur] == now) {
        t ^= 1;
        cur /= now;
      }
      if (t) res *= now, divsor[i].push_back(now);
    }
  }
}
int f[20], last[M][8];
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    query[r].push_back(make_pair(l, i));
  }
  init();
  memset(ans, 0x3f, sizeof ans);
  for (int i = 1; i <= n; i++) {
    int sd = divsor[i].size(), S = (1 << sd);
    for (int s = 0; s < S; s++) {
      int d = 1, chos = __builtin_popcount(s);
      for (int j = 0; j < sd; j++)
        if (s & (1 << j)) d *= divsor[i][j];
      for (int ans = 0; ans <= 14; ans++) {
        int fro = ans + 2 * chos - sd;
        if (fro >= 0 && fro <= 7) f[ans] = max(f[ans], last[d][fro]);
      }
    }
    for (int s = 0; s < S; s++) {
      int d = 1, chos = __builtin_popcount(s);
      for (int j = 0; j < sd; j++)
        if (s & (1 << j)) d *= divsor[i][j];
      last[d][sd] = i;
    }
    for (int j = 0; j < query[i].size(); j++) {
      for (int ans = 0; ans <= 14; ans++) {
        if (f[ans] >= query[i][j].first) {
          ::ans[query[i][j].second] = min(::ans[query[i][j].second], ans);
        }
      }
    }
  }
  for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
  return 0;
}
