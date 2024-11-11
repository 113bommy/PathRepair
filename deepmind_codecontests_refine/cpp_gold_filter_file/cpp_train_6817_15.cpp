#include <bits/stdc++.h>
using namespace std;
const int MAXN = 102;
int R, P, S;
bool visited[3][MAXN][MAXN][MAXN];
double dp[3][MAXN][MAXN][MAXN];
double f(int t, int r, int p, int s) {
  if (!r && !p && !s) {
    return 0;
  } else if (r && !p && !s) {
    return t == 0;
  } else if (!r && p && !s) {
    return t == 1;
  } else if (!r && !p && s) {
    return t == 2;
  }
  double &result = dp[t][r][p][s];
  if (visited[t][r][p][s]) {
    return result;
  }
  visited[t][r][p][s] = true;
  double sum = r * p + r * s + p * s;
  if (r && p) {
    result += f(t, r - 1, p, s) * ((r * p) / sum);
  }
  if (r && s) {
    result += f(t, r, p, s - 1) * ((r * s) / sum);
  }
  if (p && s) {
    result += f(t, r, p - 1, s) * ((p * s) / sum);
  }
  return result;
}
int main() {
  cin >> R >> S >> P;
  printf("%.10lf %.10lf %.10lf\n", f(0, R, P, S), f(2, R, P, S), f(1, R, P, S));
  return 0;
}
