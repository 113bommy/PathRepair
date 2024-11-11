#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long int n;
  cin >> n;
  if (n % 2 == 0) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  vector<long long int> A(2 * n);
  long long int f = 0;
  long long int j = 1;
  for (long long int i = 0; i < n; i++) {
    if (f == 0) {
      A[i] = j;
      A[n + i] = j + 1;
      f = 1;
      j = j + 2;
    } else {
      A[i] = j + 1;
      A[n + i] = j;
      f = 0;
      j = j + 2;
    }
  }
  for (long long int i = 0; i < 2 * n; i++) {
    cout << A[i] << " ";
  }
  return 0;
}
