#include <bits/stdc++.h>
using namespace std;
int n, i, X[200005], poz, nr0;
long long A[200005], B[200005], val, t;
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> t;
  for (i = 1; i <= n; i++) cin >> A[i];
  for (i = 1; i <= n; i++) {
    cin >> X[i];
    if (X[i] < X[i - 1]) {
      cout << "No\n";
      return 0;
    }
    if (X[i] < i) {
      cout << "No\n";
      return 0;
    }
    if (X[i - 1] != X[i] && X[i - 1] != (i - 1)) {
      cout << "No\n";
      return 0;
    }
  }
  A[n + 1] = A[n] + 1000000001;
  for (i = 1; i <= n; i++) B[X[i]] = A[X[i] + 1] + t - 1;
  val = B[n] - 1;
  for (i = n - 1; i >= 1; i--) {
    if (B[i] != 0)
      val = B[i];
    else {
      if (B[i] < A[i + 1] + t) {
        cout << "No\n";
        return 0;
      }
    }
    B[i] = val;
    val--;
  }
  cout << "Yes\n";
  for (i = 1; i <= n; i++) cout << B[i] << " ";
  cout << "\n";
  return 0;
}
