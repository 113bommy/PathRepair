#include <bits/stdc++.h>
using namespace std;
const int maxRounds = 100000;
double p[110], ans, pw[110][maxRounds + 10];
int times[110], n;
int main() {
  cin >> n;
  if (n == 1) {
    cout << 1;
    return 0;
  }
  for (int i = 1; i <= n; ++i) {
    int first;
    cin >> first;
    p[i] = first / 100.0;
  }
  double initProd = 1;
  for (int i = 1; i <= n; ++i) {
    initProd *= p[i];
    pw[i][0] = 1;
    times[i] = 1;
    for (int j = 1; j <= maxRounds; ++j) {
      pw[i][j] = pw[i][j - 1] * (1 - p[i]);
    }
  }
  ans += initProd * n;
  for (int round = n + 1; round <= maxRounds; ++round) {
    double best = 0;
    int besti = 1;
    double prod = 1;
    for (int j = 1; j <= n; ++j) prod *= (1 - pw[j][times[j]]);
    for (int j = 1; j <= n; ++j) {
      double current = prod / (1 - pw[j][times[j]]) * pw[j][times[j]] * p[j];
      if (current > best) {
        besti = j;
        best = current;
      }
    }
    ans += best * round;
    times[besti]++;
  }
  cout << fixed << setprecision(8) << ans;
}
