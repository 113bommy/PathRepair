#include <bits/stdc++.h>
using namespace std;
int n;
int Start[5], End[5];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> Start[i] >> End[i];
  }
  long double ans = 0;
  for (int i = 0; i < 10000; i++) {
    for (int j = 0; j < n; j++) {
      for (int l = 0; l < (1 << n); l++) {
        if ((l & ~(1 << j)) == 0) continue;
        long double prob = 1;
        prob = (End[j] - i) / (long double)(End[j] - Start[j] + 1);
        prob = ((prob) > (1L) ? (1L) : (prob));
        prob = ((prob) < (0L) ? (0L) : (prob));
        if (l & (1 << j)) {
          prob = 0;
          if (i >= Start[j] && i <= End[j]) {
            prob = 1 / (long double)(End[j] - Start[j] + 1);
          }
        }
        for (int k = 0; k < n; k++) {
          if (k == j) continue;
          long double prob2 = (long double)(i - Start[k]) /
                              (long double)(End[k] - Start[k] + 1);
          prob2 = ((prob2) > (1L) ? (1L) : (prob2));
          prob2 = ((prob2) < (0L) ? (0L) : (prob2));
          if (l & (1 << k)) {
            prob2 = 0;
            if (i >= Start[k] && i <= End[k]) {
              prob2 = 1. / (long double)(End[k] - Start[k] + 1);
            }
          }
          prob *= prob2;
        }
        if (l & (1 << j)) {
          prob /= __builtin_popcount(l);
        }
        ans += prob * i;
      }
    }
  }
  printf("%.15f\n", (double)ans);
}
