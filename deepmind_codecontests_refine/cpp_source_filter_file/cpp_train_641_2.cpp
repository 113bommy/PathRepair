#include <bits/stdc++.h>
using namespace std;
int main() {
  int A[4];
  cin >> A[0] >> A[1] >> A[2] >> A[3];
  sort(A, A + 4);
  if (A[0] + A[3] == A[1] + A[2])
    cout << "YES";
  else if (A[3] = A[1] + A[0] + A[2])
    cout << "YES";
  else
    cout << "NO";
}
