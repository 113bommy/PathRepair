#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n < 11) {
    cout << 0 << endl;
    return 0;
  }
  std::string s;
  cin >> s;
  int A[10];
  memset(A, 0, sizeof(A));
  for (int i = 0; i <= n - 1; i++) {
    A[s.at(i) - '0']++;
  }
  if (A[8] < 1) {
    cout << 0 << endl;
    return 0;
  }
  int poss = n / 11;
  if (poss > A[8]) {
    cout << A[8] << endl;
    return 0;
  }
  if (poss < A[8]) {
    cout << poss << endl;
    return 0;
  }
  return 0;
}
