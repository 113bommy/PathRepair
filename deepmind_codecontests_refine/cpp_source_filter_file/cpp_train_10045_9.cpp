#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  long long k;
  cin >> n >> k;
  int D[n + 1], S[n + 1], A[n + 1];
  D[1] = 1;
  D[2] = 1;
  S[1] = 1;
  S[2] = 2;
  S[0] = 0;
  S[3] = 3;
  D[3] = 1;
  for (int i = 4; i <= n; i++) {
    D[i] = D[i - 1] + D[i - 2];
    S[i] = S[i - 1] + D[i];
  }
  for (int i = 1; i <= n; i++) {
    A[i] = n - i + 1;
  }
  for (int i = n; i >= 1; i--) {
    if (S[i - 1] < k && k > 1) {
      swap(A[i], A[i - 1]);
      k -= S[i - 1];
      if (k <= 1) {
        break;
      }
    }
  }
  for (int i = n; i >= 1; i--) {
    cout << A[i] << " ";
  }
  return 0;
}
