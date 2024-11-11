#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 30;
const int N = 100100;
int n, a[N], m;
vector<pair<int, int> > adj[102];
int mem[102][102][27][2];
int dp(int i, int j, int last, int turn) {
  int &ret = mem[i][j][last][turn];
  if (ret != -1) return ret;
  if (!turn) {
    ret = 0;
    for (auto v : adj[i]) {
      if (v.second >= last) ret |= dp(v.first, j, v.second, 1 - turn);
    }
  } else {
    ret = 1;
    for (auto v : adj[j]) {
      if (v.second >= last) ret &= dp(i, v.first, v.second, 1 - turn);
    }
  }
  return ret;
}
int main() {
  scanf("%d %d", &n, &m);
  char al[2];
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d %d %s", &x, &y, al);
    adj[x].push_back({y, al[0] - 'a'});
  }
  memset(mem, -1, sizeof mem);
  for (int A = 1; A <= n; A++) {
    for (int B = 1; B <= n; B++) {
      if (dp(A, B, 0, 0))
        printf("A");
      else
        printf("B");
    }
    printf("\n");
  }
  return 0;
}
