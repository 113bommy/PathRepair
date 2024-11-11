#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> A, B;
  int sum1 = 0, sum2 = 0;
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    A.push_back(a);
    sum1 += A[i - 1];
  }
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    B.push_back(a);
    sum2 += B[i];
  }
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  if (sum1 == sum2) {
    if (A[0] == B[n - 1])
      cout << -1 << endl;
    else {
      int yy = A[0];
      A[0] = B[n - 1];
      B[n - 1] = yy;
      for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
      }
      for (int i = 0; i < n; i++) {
        cout << B[i] << " ";
      }
    }
  } else {
    for (int i = 0; i < n; i++) {
      cout << A[i] << " ";
    }
    for (int i = 0; i < n; i++) {
      cout << B[i] << " ";
    }
  }
}
