#include <bits/stdc++.h>
using namespace std;
int n = 250;
int T, A[250];
int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(0);
  cin >> T;
  for (int t = 0; t < T; t++) {
    int maxi = 0, mini = INT_MAX, sum = 0, sum2 = 0, sum4 = 0;
    for (int i = 0; i < n; i++) {
      cin >> A[i];
      mini = min(mini, A[i]);
      maxi = max(maxi, A[i]);
      sum4 += A[i] * A[i] * A[i] * A[i];
      sum2 += A[i] * A[i];
    }
    double k = float(sum4) / sum2 / sum2 * n;
    k -= 3;
    cout << (k < -0.7 ? "uniform" : "poisson") << endl;
  }
}
