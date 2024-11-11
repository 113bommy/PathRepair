#include <bits/stdc++.h>
using namespace std;
inline int setBit(int N, int pos) { return N = N | (1 << pos); }
inline int resetBit(int N, int pos) { return N = N & ~(1 << pos); }
inline bool checkBit(int N, int pos) { return (bool)(N & (1 << pos)); }
int n, m;
char s[5];
vector<pair<int, int> > E[100 + 10];
int dp[100 + 10][100 + 10][30][2];
int call(int a, int b, int last, bool nw) {
  int &ret = dp[a][b][last][nw];
  if (ret != -1) return ret;
  if (nw == 0) {
    int best = 0;
    for (auto v : E[a]) {
      if (v.second >= last) best |= call(v.first, b, v.second, 1);
    }
    return ret = best;
  } else {
    int best = 1;
    for (auto v : E[b]) {
      if (v.second >= last) best |= call(a, v.first, v.second, 0);
    }
    return ret = best;
  }
}
int main() {
  memset((dp), -1, sizeof(dp));
  scanf("%d %d", &n, &m);
  int u, v;
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", &u, &v);
    scanf("%s", s);
    E[u].push_back({v, s[0] - 'a'});
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (call(i, j, 0, 0))
        printf("A");
      else
        printf("B");
    }
    puts("");
  }
  return 0;
}
