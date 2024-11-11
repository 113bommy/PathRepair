#include <bits/stdc++.h>
using namespace std;
int T, A[250];
int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(0);
  cin >> T;
  for (int t = 0; t < T; t++) {
    int maxi = 0, mini = INT_MAX, sum = 0, sum2 = 0;
    for (int i = 0; i < 250; i++) {
      cin >> A[i];
      mini = min(mini, A[i]);
      maxi = max(maxi, A[i]);
      sum += A[i];
      sum2 += A[i] * A[i];
    }
    double P = sum / 250.0;
    if (sum2 > 1.2 * P * P * 250) {
      cout << (maxi + 1) / 2 << endl;
    } else
      cout << int(P + 0.5) << endl;
  }
}
