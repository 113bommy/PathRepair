#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, z;
  cin >> n >> z;
  if (z == 0) {
    if (n % 2 == 0)
      cout << 1;
    else
      cout << 0;
    return 0;
  }
  if (n % 2 == 0 && z % 2 == 1) {
    cout << 0;
    return 0;
  }
  long long a = n;
  long long b = z;
  if (n < z) {
    cout << "0";
    return 0;
  }
  vector<int> A;
  vector<int> B;
  while (n > 0) {
    A.push_back(n % 2);
    n = n / 2;
  }
  while (z > 0) {
    B.push_back(z % 2);
    z = z / 2;
  }
  while (B.size() < A.size()) {
    B.push_back(0);
  }
  reverse(A.begin(), A.end());
  reverse(B.begin(), B.end());
  long long x = 1;
  long long y = 0;
  for (int i = A.size() - 1; i >= 0; i--) {
    if (A[i] == 1 && B[i] == 1) {
      x = x * 2;
      y = 0;
    }
    if (A[i] == 0 && B[i] == 0) {
      y = x;
    }
    if (A[i] == 1 && B[i] == 0) {
      x = y;
    }
    if (A[i] == 0 && B[i] == 1) {
      y = x * 2;
      x = 0;
    }
  }
  if (a == b) {
    cout << x - 2;
    return 0;
  }
  cout << x;
  return 0;
}
