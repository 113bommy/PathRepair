#include <bits/stdc++.h>
using namespace std;
long double prob[2015][2015];
void solution() {
  int n, t;
  long double p;
  cin >> n >> p >> t;
  long double q = 1 - p;
  memset((prob), (0), sizeof(prob));
  prob[0][0] = 1;
  for (int i = (1); i <= (t); i++) {
    prob[0][i] = prob[0][i - 1] * q;
    for (int j = (1); j <= ((((i) < (n)) ? (i) : (n))); j++) {
      prob[j][i] = prob[j - 1][i - 1] * p + prob[j][i - 1] * q;
    }
    if (i > n) prob[n][i] += prob[n][i - 1] * q;
  }
  long double ans = 0;
  for (int i = (1); i <= (n); i++) {
    ans += i * prob[i][t];
  }
  printf("%.9f\n", ans);
}
int main() { solution(); }
