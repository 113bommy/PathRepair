#include <bits/stdc++.h>
using namespace std;
int mult[] = {1000, 100, 10, 1};
int main() {
  int i, j, k;
  int best, candidate, subtr;
  int n;
  cin >> n;
  int dates[n + 1];
  dates[0] = 1000;
  for (i = 1; i < n + 1; i++) {
    cin >> dates[i];
  }
  for (i = 1; i < n + 1; i++) {
    best = 2012;
    for (j = 0; j < 4; j++) {
      subtr = (dates[i] % (mult[j] * 10)) / mult[j] * mult[j];
      for (k = j == 0 ? 1 : 0; k < 10; k++) {
        candidate = dates[i] - subtr + k * mult[j];
        if (candidate >= dates[i - 1] && candidate < best) {
          best = candidate;
        }
      }
    }
    if (best == 2012) {
      cout << "No solution" << endl;
      return 0;
    }
    dates[i] = best;
  }
  for (i = 1; i < n + 1; i++) {
    cout << dates[i] << endl;
  }
}
