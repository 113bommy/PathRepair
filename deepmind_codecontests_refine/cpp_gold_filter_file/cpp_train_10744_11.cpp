#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long n;
  cin >> n;
  while (n--) {
    unsigned long long A[3];
    cin >> A[0] >> A[1] >> A[2];
    sort(A, A + 3);
    if (A[2] - 1 > A[0] + A[1])
      cout << "No" << endl;
    else
      cout << "Yes" << endl;
  }
}
