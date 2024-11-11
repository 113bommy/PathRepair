#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, i, j, k, l, s, d;
  bool prime[1000000 + 1];
  memset(prime, true, sizeof(prime));
  for (int p = 2; p * p <= 1000000; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= 1000000; i += p) prime[i] = false;
    }
  }
  prime[1] = false;
  cin >> a;
  cin >> b;
  long long c[a][b];
  for (i = 0; i < a; i++) {
    for (j = 0; j < b; j++) {
      cin >> c[i][j];
    }
  }
  vector<long long> x;
  for (i = 0; i < a; i++) {
    s = 0;
    for (j = 0; j < b; j++) {
      if (prime[c[i][j]] != true) {
        for (k = c[i][j]; k <= 100000; k++) {
          if (prime[k] == true) {
            l = k;
            break;
          }
        }
        s = s + l - c[i][j];
      }
    }
    if (s >= 0) {
      x.push_back(s);
    }
  }
  for (j = 0; j < b; j++) {
    s = 0;
    for (i = 0; i < a; i++) {
      if (prime[c[i][j]] != true) {
        for (k = c[i][j]; k <= 100000; k++) {
          if (prime[k] == true) {
            l = k;
            break;
          }
        }
        s = s + l - c[i][j];
      }
    }
    if (s >= 0) {
      x.push_back(s);
    }
  }
  sort(x.begin(), x.end());
  cout << x[0] << endl;
}
