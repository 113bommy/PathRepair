#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int q = 0;
  int a, b;
  int A[n], B[n];
  for (int i = 0; i < n; ++i) {
    cin >> A[i] >> B[i];
  }
  for (int i = 0; i < n; ++i) {
    a = A[i];
    b = B[i];
    if (q + a > 500) {
      q -= b;
      cout << "G";
    } else {
      q += b;
      cout << "A";
    }
  }
  return 0;
}
