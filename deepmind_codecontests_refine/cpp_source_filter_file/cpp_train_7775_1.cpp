#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int D[2345][2];
int dp[2001][10000];
int f(int ins, int down, int up, int tar) {
  int u = abs(up - down);
  int a = abs(down - ins) + u + abs(tar - up);
  int b = abs(up - ins) + u + abs(tar - down);
  return min(a, b);
}
int ff(int ins, int down, int up) {
  int u = abs(up - down);
  int a = abs(down - ins) + u;
  int b = abs(up - ins) + u;
  return min(a, b);
}
map<int, int> M;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d%d", &D[i][0], &D[i][1]);
  fill(&dp[0][0], &dp[2000][0], INF);
  dp[0][D[0][1]] = abs(D[0][0] - 1) + 1;
  int ans = INF;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 10000; j++) {
      if (dp[i][j] != INF) {
        int ins = D[i][0];
        int p = j;
        M.clear();
        while (p > 0) {
          if (p % 10 != 0) M[p % 10]++;
          p /= 10;
        }
        int s1 = 0;
        for (int g = ins; g > 0; g--) {
          if (g == ins || M[g] > 0) {
            s1 += M[g];
            int s2 = 0;
            for (int g1 = ins; g1 < 10; g1++)
              if (g1 == ins || M[g1] > 0) {
                s2 += M[g1];
                int cost = f(ins, g, g1, D[i + 1][0]) + s1 + s2 + 1;
                int v = D[i + 1][1], h = 10;
                for (auto k : M) {
                  if (k.first < g || k.first > g1) {
                    for (int f = 0; f < k.second; f++)
                      v += h * k.first, h *= 10;
                  }
                }
                if (i == n - 1) {
                  if (h == 10) {
                    int cost = ff(ins, g, g1) + s1 + s2 + dp[i][j];
                    ans = min(ans, cost);
                  }
                } else if (h < 10000) {
                  dp[i + 1][v] = min(dp[i + 1][v], cost + dp[i][j]);
                }
              }
          }
        }
      }
    }
  }
  cout << ans << '\n';
}
