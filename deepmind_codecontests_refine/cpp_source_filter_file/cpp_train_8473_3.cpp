#include <bits/stdc++.h>
using namespace ::std;
int A[100000];
int C[10];
int main(void) {
  int n;
  memset(C, 0, sizeof C);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    C[A[i]]++;
  }
  if (C[1] == (n / 3) && (C[2] + C[3] == C[4] + C[6]) && C[5] == 0 &&
      C[7] == 0 && C[6] >= C[3]) {
    for (int i = 0; i < C[4]; i++) cout << 1 << " " << 2 << " " << 4 << endl;
    for (int i = 0; i < C[2] - C[6]; i++)
      cout << 1 << " " << 2 << " " << 6 << endl;
    for (int i = 0; i < C[3]; i++) cout << 1 << " " << 3 << " " << 6 << endl;
  } else
    cout << -1 << endl;
  return 0;
}
