#include <bits/stdc++.h>
using namespace std;
bool check23(int n) {
  while (n % 2 == 0) {
    n /= 2;
  }
  while (n % 3 == 0) {
    n /= 3;
  }
  return n == 1 ? true : false;
}
int main() {
  int n;
  cin >> n;
  vector<int> A;
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    A.push_back(temp);
  }
  int f = A[0];
  while (A[0] % 2 == 0) {
    A[0] /= 2;
  }
  while (A[0] % 3 == 0) {
    A[0] /= 3;
  }
  f = A[0];
  int x = 1;
  for (int i = 1; i < n; i++) {
    if (A[i] % f != 0 || check23(A[i] / f) == 0) {
      cout << "NO" << endl;
      x = 0;
      break;
    }
  }
  if (x) cout << "YES" << endl;
  return 0;
}
