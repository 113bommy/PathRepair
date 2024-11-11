#include <bits/stdc++.h>
using namespace std;
long long A[100005];
long long R[100005];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> A[i];
  for (int i = 0; i < n / 2; i++) {
    if (i % 2 == 0) {
      R[i] = A[n - i - 1];
      R[n - i - 1] = A[i];
    } else {
      R[i] = A[i];
      R[n - i - 1] = A[n - i - 1];
    }
  }
  for (int i = 0; i < n; i++) {
    cout << R[i] << " ";
  }
  return 0;
}
