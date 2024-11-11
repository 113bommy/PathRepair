#include <bits/stdc++.h>
using namespace std;
double dp[51][200001];
double S[200001], T[200001], ST[200001];
int Q[200001];
int n, m;
inline double gg(int s, int e) {
  if (e == s + 1) return 1;
  return ST[e] - ST[s] - S[s] * (T[e] - T[s]);
}
inline double g(pair<double, double> a, pair<double, double> b) {
  return (b.second - a.second) / (a.first - b.first);
}
inline double f(pair<double, double> x, int i) {
  return x.first * T[i] + x.second + ST[i];
}
inline double cmp(double x, double y) {
  return (fabs(x - y) < 1e-8) || (x < y);
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < (n); i++) scanf("%d", Q + i + 1);
  for (int i = 0; i < (n); i++) {
    S[i + 1] = S[i] + Q[i + 1];
    T[i + 1] = T[i] + 1.0 / Q[i + 1];
    ST[i + 1] = ST[i] + S[i + 1] / Q[i + 1];
  }
  for (int i = (1); i <= (n); i++) dp[0][i] = gg(0, i);
  for (int k = (1); k <= (m - 1); k++) {
    deque<pair<double, double> > dq;
    dq.push_back(make_pair(0, 0));
    for (int i = (1); i <= (n); i++) {
      double a = -S[i], b = -ST[i] + S[i] * T[i] + dp[k - 1][i];
      pair<double, double> tmp = make_pair(a, b);
      while (dq.size() > 1 && cmp(g(dq[dq.size() - 2], tmp),
                                  g(dq[dq.size() - 2], dq[dq.size() - 1])))
        dq.pop_back();
      dq.push_back(tmp);
      while (dq.size() > 1 && cmp(f(dq[1], i), f(dq[0], i))) dq.pop_front();
      dp[k][i] = f(dq[0], i);
    }
  }
  printf("%.9f\n", dp[m - 1][n]);
  return 0;
}
