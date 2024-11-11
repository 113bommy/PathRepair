#include <bits/stdc++.h>
using namespace std;
int L[6];
int R[6];
long double probval[11111];
int main() {
  int n;
  cin >> n;
  int M = 10000;
  for (int i = 1; i <= n; i++) {
    cin >> L[i] >> R[i];
    M = max(M, R[i]);
  }
  long double answer = 0;
  for (int mask = 1; mask < (1 << n); mask++) {
    set<int> ids;
    for (int j = 0; j < n; j++) {
      if ((mask >> j) & 1) ids.insert(j + 1);
    }
    for (int j = 0; j <= M; j++) {
      probval[j] = 1;
      for (int k = 1; k <= n; k++) {
        if (ids.find(k) != ids.end()) {
          continue;
        }
        if (L[k] > j) {
          probval[j] = 0.0;
        } else if (L[k] <= j && R[k] >= j) {
          probval[j] *= (j - L[k] + 1.0) / (R[k] - L[k] + 1.0);
        }
      }
    }
    for (int j = M; j >= 1; j--) {
      probval[j] -= probval[j - 1];
    }
    long double sume;
    if (ids.size() > 1)
      sume = probval[0];
    else
      sume = 0;
    for (int m = 1; m <= M; m++) {
      long double prodval = 1.0;
      for (set<int>::iterator it = ids.begin(); it != ids.end(); ++it) {
        int i = *it;
        if (R[i] >= m && L[i] <= m)
          prodval *= 1.0 / (R[i] - L[i] + 1.0);
        else
          prodval = 0.0;
      }
      if (ids.size() > 1)
        answer += prodval * sume * m;
      else
        answer += prodval * sume;
      if (ids.size() > 1)
        sume += probval[m];
      else
        sume += probval[m] * m;
    }
  }
  printf("%1.10Lf\n", answer);
}
