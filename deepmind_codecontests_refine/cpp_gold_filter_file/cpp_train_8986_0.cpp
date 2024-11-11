#include <bits/stdc++.h>
using namespace std;
double dp1[5000][201], dp2[5000][201];
double p1, p2;
int l1, r1, l2, r2, DT1, DT2;
void precomp(int hp1, int hp2) {
  dp1[0][hp1] = 1;
  for (int k = 0; k < 5000 - 1; k++) {
    for (int i = hp1; i >= 0; i--) {
      if (dp1[k][i] < 1e-8) continue;
      double diff = 1.0 / (r2 - l2 + 1);
      for (int j = l2; j <= r2; j++) {
        dp1[k + 1][max(i - j, 0)] += dp1[k][i] * diff * (1 - p2);
        dp1[k + 1][i] += dp1[k][i] * diff * p2;
      }
    }
  }
  dp2[0][hp2] = 1;
  for (int k = 0; k < 5000 - 1; k++) {
    for (int i = hp2; i >= 0; i--) {
      if (dp2[k][i] < 1e-8) continue;
      double diff = 1.0 / (r1 - l1 + 1);
      for (int j = l1; j <= r1; j++) {
        dp2[k + 1][max(i - j, 0)] += dp2[k][i] * diff * (1 - p1);
        dp2[k + 1][i] += dp2[k][i] * diff * p1;
      }
    }
  }
}
int main() {
  int hp1, hp2;
  cin >> hp1 >> DT1 >> l1 >> r1 >> p1;
  cin >> hp2 >> DT2 >> l2 >> r2 >> p2;
  if (p1 == 100) {
    cout << 0 << endl;
    return 0;
  }
  if (p2 == 100) {
    cout << 1 << endl;
    return 0;
  }
  p1 /= 100;
  p2 /= 100;
  precomp(hp1, hp2);
  int s1 = 0, s2 = 0;
  double ans = 0, carry = 1;
  for (int dt = 0; s1 < 5000 - 1 && s2 < 5000; dt++) {
    if (dt % DT1 == 0) {
      s1++;
      ans += (1 - dp1[s2][0]) * (dp2[s1][0] - dp2[s1 - 1][0]);
    }
    if (dt % DT2 == 0) {
      s2++;
    }
  }
  cout.precision(6);
  cout << fixed << ans << endl;
  return 0;
}
