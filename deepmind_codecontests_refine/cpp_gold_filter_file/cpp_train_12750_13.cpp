#include <bits/stdc++.h>
using namespace std;
string S;
int A[10], B[10];
int main() {
  memset(A, 0, sizeof(A));
  ;
  memset(B, 0, sizeof(B));
  ;
  int n;
  cin >> n >> S;
  for (int i = 0; (i) < (int((S).size())); i++) {
    int k = S[i] - '0';
    A[k]++;
    for (int j = (k - 1); (j) >= (2); j--) {
      A[j]++;
    }
  }
  B[3] += 2 * A[9];
  B[2] += 3 * A[8];
  B[7] += A[7];
  B[3] += A[6];
  B[2] += A[6];
  B[5] += A[5];
  B[2] += 2 * A[4];
  B[3] += A[3];
  B[2] += A[2];
  int k = B[7];
  for (int i = 0; (i) < (k); i++) {
    cout << "7";
    B[7]--;
    B[5]--;
    B[3] -= 2;
    B[2] -= 4;
  }
  k = B[5];
  for (int i = 0; (i) < (k); i++) {
    cout << "5";
    B[5]--;
    B[3]--;
    B[2] -= 3;
  }
  k = B[3];
  for (int i = 0; (i) < (k); i++) {
    cout << "3";
    B[3]--;
    B[2]--;
  }
  for (int i = 0; (i) < (B[2]); i++) cout << "2";
  cout << endl;
  return 0;
}
