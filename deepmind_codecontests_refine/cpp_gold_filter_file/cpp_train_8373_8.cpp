#include <bits/stdc++.h>
using namespace std;
int C[2][255];
int main() {
  string A, B;
  getline(cin, A);
  for (int i = 0; i < A.size(); i++) C[0][A[i]]++;
  getline(cin, B);
  for (int i = 0; i < B.size(); i++) C[1][B[i]]++;
  C[0][' '] = C[1][' '];
  for (int i = 0; i < 255; i++)
    if (C[0][i] < C[1][i]) {
      cout << "NO" << endl;
      return 0;
    }
  cout << "YES" << endl;
  return 0;
}
