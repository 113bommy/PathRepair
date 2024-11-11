#include <bits/stdc++.h>
using namespace std;
int A[3];
int main() {
  cin >> A[0] >> A[1] >> A[2];
  sort(A, A + 3);
  if ((A[1] - A[0]) % 2 == 0)
    cout << A[1] << endl;
  else
    cout << A[2] << endl;
  return 0;
}
