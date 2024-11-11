#include <bits/stdc++.h>
using namespace std;
void RI() {}
template <typename... T>
void RI(int& head, T&... tail) {
  scanf("%d", &head);
  RI(tail...);
}
inline void chkmin(double& a, double b) {
  if (b < a) a = b;
}
int n, l, x[1010], b[1010];
double d[1010][1010];
double dp[1010];
bool chk(double m) {
  dp[0] = 0;
  for (int i = (1); i <= int(n); i++) {
    double mi = 1e100;
    for (int j = (0); j <= int(i - 1); j++) chkmin(mi, dp[j] + d[j][i]);
    dp[i] = mi - m * b[i];
  }
  return dp[n] <= 0;
}
int frm[1010];
void trace(double m) {
  dp[0] = 0;
  for (int i = (1); i <= int(n); i++) {
    double mi = 1e100;
    for (int j = (0); j <= int(i - 1); j++)
      if (dp[j] + d[j][i] < mi) {
        mi = dp[j] + d[j][i];
        frm[i] = j;
      }
    dp[i] = mi - m * b[i];
  }
  vector<int> sol;
  for (int i = n; i; i = frm[i]) sol.push_back(i);
  reverse(begin(sol), end(sol));
  for (int i = 0; i < int(((int)(sol).size())); i++)
    printf("%d%c", sol[i], i + 1 == ((int)(sol).size()) ? '\n' : ' ');
}
int main() {
  RI(n, l);
  for (int i = (1); i <= int(n); i++) RI(x[i], b[i]);
  for (int i = (0); i <= int(n); i++)
    for (int j = (i + 1); j <= int(n); j++)
      d[i][j] = sqrt((double)abs(x[j] - x[i] - l));
  double ll = 0, rr = 1e9;
  for (int i = 0; i < int(50); i++) {
    double mm = (ll + rr) / 2;
    if (chk(mm))
      rr = mm;
    else
      ll = mm;
  }
  double mm = (ll + rr) / 2;
  trace(mm);
  return 0;
}
