#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = (int)1e9 + 7;
const int N = (int)1e6 + 7;
int n;
int c[N], in[N], tin[N];
vector<int> e[N], Q[4], tQ[4];
void Init() {
  for (int i = (1); i < (4); ++i) Q[i].clear();
  memset(in, 0, sizeof(in));
  for (int i = (0); i < (n + 1); ++i) e[i].clear();
  for (int i = (1); i < (n + 1); ++i) scanf("%d", c + i);
  for (int i = (1); i < (n + 1); ++i) {
    int k;
    scanf("%d", &k);
    for (int j = (0); j < (k); ++j) {
      int v;
      scanf("%d", &v);
      e[v].push_back(i);
      in[i]++;
    }
  }
}
bool check() {
  bool ok = 1;
  for (int i = (1); i < (4); ++i)
    if ((int)(Q[i]).size()) ok = 0;
  return ok;
}
int work(int start) {
  int cnt = 0;
  for (int i = start;; i = i % 3 + 1) {
    if (check())
      break;
    else
      cnt++;
    for (int j = (0); j < ((int)(Q[i]).size()); ++j) {
      int u = Q[i][j];
      cnt++;
      for (auto o : e[u]) {
        in[o]--;
        if (!in[o]) Q[c[o]].push_back(o);
      }
    }
    Q[i].clear();
  }
  return cnt;
}
int Solve() {
  for (int i = (1); i < (n + 1); ++i)
    if (!in[i]) Q[c[i]].push_back(i);
  for (int i = (1); i < (n + 1); ++i) tin[i] = in[i];
  for (int i = (1); i < (4); ++i) tQ[i] = Q[i];
  int ans = INF;
  for (int i = (1); i < (4); ++i) {
    for (int j = (1); j < (4); ++j) Q[j] = tQ[j];
    for (int j = (1); j < (n + 1); ++j) in[j] = tin[j];
    ans = min(ans, work(i));
  }
  return printf("%d\n", ans - 1);
}
int main() {
  while (~scanf("%d", &n)) {
    Init();
    Solve();
  }
  return 0;
}
