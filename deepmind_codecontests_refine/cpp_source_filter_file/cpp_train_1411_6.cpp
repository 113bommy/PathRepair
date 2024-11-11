#include <bits/stdc++.h>
using namespace std;
map<vector<int>, double> M;
const int MAX = (1 << 20) + 10;
double P[30];
int X[30];
double S[MAX];
double R[30];
int main() {
  int n, m, n2 = 0;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    double x;
    scanf("%lf", &x);
    if (x != 0) {
      X[i] = 1;
      P[n2] = x;
      n2++;
    }
  }
  m = min(m, n2);
  for (int i = 0; i < n2; i++) {
    S[1 << i] = P[i];
  }
  for (int i = 1; i < m; i++) {
    for (int j = (1 << i) - 1; j < 1 << n2;) {
      double tot = 1;
      for (int k = j, x = 1; k;) {
        if (k % 2) tot -= S[x];
        x *= 2;
        k /= 2;
      }
      for (int k = j, x = 1, l = 0; l < n2;) {
        if (k % 2 == 0) S[j + x] += S[j] * S[x] / tot;
        x *= 2;
        l++;
        k /= 2;
      }
      int smallest = (j & -j);
      int ripple = j + smallest;
      int new_smallest = (ripple & -ripple);
      int ones = ((new_smallest / smallest) >> 1) - 1;
      j = ripple | ones;
    }
  }
  double tot = 0;
  for (int i = (1 << m) - 1; i < 1 << n2;) {
    tot += S[i];
    for (int j = i, x = 1; j;) {
      if (j % 2) {
        R[x] += S[i];
      }
      x *= 2;
      j /= 2;
    }
    int smallest = (i & -i);
    int ripple = i + smallest;
    int new_smallest = (ripple & -ripple);
    int ones = ((new_smallest / smallest) >> 1) - 1;
    i = ripple | ones;
  }
  for (int i = 0, j = 0; i < n; i++) {
    if (X[i]) {
      printf("%.10f\n", R[(1 << j)] / tot);
      j++;
    } else {
      printf("0\n");
    }
  }
}
