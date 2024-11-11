#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B, C = 0, D = 0, K = 0;
  cin >> A >> B;
  for (int i = 1; i <= 6; i++) {
    if (abs(A - i) > abs(B - i))
      C++;
    else if (abs(A - i) < abs(B - i))
      D++;
    else
      K++;
  }
  printf("%d %d %d", C, K, D);
}
