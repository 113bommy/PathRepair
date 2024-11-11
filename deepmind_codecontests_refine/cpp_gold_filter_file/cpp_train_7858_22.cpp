#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  vector<int> B(n, 1);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  int max1 = B[0];
  for (int i = 1; i < n; i++) {
    if (A[i] >= A[i - 1]) {
      B[i] = B[i - 1] + 1;
    }
    max1 = max(max1, B[i]);
  }
  cout << max1;
  return 0;
}
