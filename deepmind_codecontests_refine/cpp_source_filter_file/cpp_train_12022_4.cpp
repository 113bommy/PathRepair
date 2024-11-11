#include <bits/stdc++.h>
using namespace std;
int n, l[5], r[5];
double result;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> l[i] >> r[i];
  for (int winner = 0; winner < n; winner++) {
    double probmore = 0;
    for (int i = l[winner]; i <= r[winner]; i++)
      probmore += 1.0 / (r[winner] - l[winner] + 1);
    double sumprob = 0;
    for (int i = 0; i <= 10000; i++) {
      if (i >= l[winner] && i <= r[winner])
        probmore -= 1.0 / (r[winner] - l[winner] + 1);
      double cprob = 1;
      for (int j = 0; j < n; j++)
        if (j != winner) {
          if (l[j] <= i)
            cprob *= 1.0 * (min(i, r[j]) - l[j] + 1) / (r[j] - l[j] + 1);
          else
            cprob = 0;
        }
      result += (cprob - sumprob) * probmore * i;
      sumprob = cprob;
    }
  }
  for (int comb = 1; comb < (1 << n); comb++) {
    int nwinners = 0;
    bool wins[5] = {false, false, false, false, false};
    for (int i = 0; i < n; i++)
      if ((comb & (1 << i)) != 0) nwinners++, wins[i] = true;
    if (nwinners <= 1) continue;
    for (int i = 0; i < 10000; i++) {
      double cadd = 1;
      for (int j = 0; j < n; j++) {
        if (wins[j]) {
          if (i >= l[j] && i <= r[j])
            cadd *= 1.0 / (r[j] - l[j] + 1);
          else
            cadd = 0;
        } else if (!wins[j]) {
          if (i <= l[j])
            cadd = 0;
          else
            cadd *= 1.0 * (min(i, r[j] + 1) - l[j]) / (r[j] - l[j] + 1);
        }
      }
      result += cadd * i;
    }
  }
  cout << fixed << setprecision(11) << result << '\n';
  return 0;
}
