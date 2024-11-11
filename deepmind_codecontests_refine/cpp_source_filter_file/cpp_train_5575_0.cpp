#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const int INF = 1000000000;
const int MAX = 22;
double P[MAX];
double D[1 << MAX];
int C[1 << MAX];
double R[MAX];
int main() {
  int n, m;
  cin >> n >> m;
  m = min(m, n);
  for (int i = (0); i < (n); ++i) {
    cin >> P[i];
  }
  for (int i = (1); i < (1 << n); ++i) {
    C[i] = C[i >> 1] + (i & 1);
  }
  D[0] = 1;
  for (int i = (0); i < (1 << n); ++i) {
    if (C[i] > m) continue;
    double s = 0;
    for (int j = (0); j < (n); ++j) {
      if ((i & (1 << j)) == 0) s += P[j];
    }
    if (s != 0) {
      for (int j = (0); j < (n); ++j) {
        if ((i & (1 << j)) == 0) {
          D[i ^ (1 << j)] += D[i] * P[j] / s;
          R[j] += D[i] * P[j] / s;
        }
      }
    }
  }
  for (int i = (0); i < (n); ++i) {
    printf("%.9f ", R[i]);
  }
  return 0;
}
