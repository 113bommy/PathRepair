#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  long long int A[n];
  for (long long int i = 0; i < n; i++) {
    cin >> A[i];
    if (A[i] % 2 == 0) {
      cout << A[i] - 1 << " ";
    } else {
      cout << A[i] + 1 << " ";
    }
  }
  return 0;
}
