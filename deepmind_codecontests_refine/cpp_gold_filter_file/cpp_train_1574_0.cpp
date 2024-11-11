#include <bits/stdc++.h>
using namespace std;
int n, k, A;
vector<int> v, l;
double p(int N, int M, vector<int> C) {
  if (M == n) {
    vector<int> L = l;
    for (int i = 0; i < n; i++) L[i] = min(100, L[i] + C[i] * 10);
    double P = 0.0;
    for (int i = 0; i < 1 << n; i++) {
      int f = 0, B = 0;
      double q = 1.0;
      for (int j = 0; j < n; j++) {
        if (1 & (i >> j)) {
          q *= L[j] / 100.0;
          f++;
        } else {
          q *= 1.0 - L[j] / 100.0;
          B += v[j];
        }
      }
      if (f < (n + 2) / 2) q *= (double)(A) / (A + B);
      P += q;
    }
    return P;
  } else {
    double P = 0.0;
    if (M < n - 1)
      for (int i = 0; i < N + 1; i++) {
        vector<int> w = C;
        w[M] = i;
        P = max(P, p(N - i, M + 1, w));
      }
    else {
      vector<int> w = C;
      w[M] = N;
      P = max(P, p(0, M + 1, w));
    }
    return P;
  }
}
int main() {
  cin >> n >> k >> A;
  vector<int> c;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    v.push_back(a);
    l.push_back(b);
    c.push_back(0);
  }
  cout << setprecision(9) << p(k, 0, c) << endl;
}
