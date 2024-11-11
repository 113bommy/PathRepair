#include <bits/stdc++.h>
using namespace std;
int main() {
  string A;
  string B;
  cin >> A >> B;
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  int Alo = 0, Ahi = (A.size() + 1) / 2;
  int Blo = B.size() - B.size() / 2, Bhi = B.size();
  string C(A.size(), ' ');
  int Clo = 0, Chi = A.size();
  while (Clo < Chi) {
    if (A[Alo] < B[Bhi - 1]) {
      C[Clo++] = A[Alo++];
    } else {
      C[Chi--] = A[--Ahi];
    }
    if (Clo >= Chi) break;
    if (A[Alo] < B[Bhi - 1]) {
      C[Clo++] = B[--Bhi];
    } else {
      C[Chi--] = B[Blo++];
    }
  }
  cout << C;
}
