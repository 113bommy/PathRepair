#include <bits/stdc++.h>
using namespace std;
int A[1001];
int main() {
  int n;
  long long k;
  int mx = 0;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
    mx = max(mx, A[i]);
  }
  int z1 = 1;
  int z2 = 2;
  long long p = 0;
  if (k >= n - 1) {
    cout << mx;
    return 0;
  }
  while (p < k) {
    if (A[z1] > A[z2]) {
      p++;
      swap(A[z1], A[z2]);
      swap(z1, z2);
    } else {
      p = 0;
      swap(z1, z2);
    }
    z2 = z1 + 1;
    if (z2 > n) {
      z2 = 1;
    }
  }
  cout << A[z1];
  return 0;
}
