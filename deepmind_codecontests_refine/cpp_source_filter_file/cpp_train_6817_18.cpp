#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int r, p, s;
double dp[N][N][N];
int vis[N][N][N];
int tc;
double rec(int r, int p, int s) {
  if (r && !p && !s) {
    return 1.00;
  }
  if (vis[r][p][s] == tc) return dp[r][p][s];
  vis[r][p][s] = tc;
  double ans = 0.00;
  double d = p * s + r * s + p * r;
  if (p && s) {
    ans += (double)p * s * rec(r, p - 1, s) / d;
  }
  if (r && p) {
    ans += ((double)r * p * rec(r - 1, p, s)) / d;
  }
  if (r && s) {
    ans += ((double)(r * s) * rec(r, p, s - 1)) / d;
  }
  return dp[r][p][s] = ans;
}
int main() {
  cin >> r >> s >> p;
  ++tc;
  printf("%.10lf ", rec(r, p, s));
  tc++;
  printf("%.10lf ", rec(s, p, r));
  tc++;
  printf("%.10lf ", rec(p, s, r));
  tc++;
}
