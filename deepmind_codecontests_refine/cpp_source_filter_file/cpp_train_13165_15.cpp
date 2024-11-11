#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  vector<int> A(10);
  A[0] = 2, A[1] = 7, A[2] = 1, A[3] = 3, A[4] = 2, A[5] = 4, A[6] = 2,
  A[7] = 5, A[8] = 1, A[9] = 2;
  int n;
  cin >> n;
  cout << A[n % 10] * A[(n / 10) % 10];
  return 0;
}
