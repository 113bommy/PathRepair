#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a;
  int A[5] = {0, 0, 0, 0, 0};
  int B[5] = {0, 0, 0, 0, 0};
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    A[a - 1]++;
  }
  for (int i = 0; i < n; i++) {
    cin >> a;
    B[a - 1]++;
  }
  int C = 0;
  int D = 0;
  bool pari = true;
  for (int i = 0; i < 5; i++) {
    C += A[i] - B[i];
    D += abs(A[i] - B[i]);
    pari = pari && (A[i] - B[i] % 2) == 0;
  }
  if (C == 0 and D % 4 == 0 and pari)
    cout << D / 4;
  else {
    cout << -1;
  }
}
