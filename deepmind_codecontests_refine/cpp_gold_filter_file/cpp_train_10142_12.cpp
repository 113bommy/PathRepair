#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B, c = 0, d = 0, k = 0;
  cin >> A >> B;
  for (int i = 1; i <= 6; i++) {
    if (abs(A - i) > abs(B - i))
      c++;
    else if (abs(A - i) < abs(B - i))
      d++;
    else
      k++;
  }
  printf("%d %d %d", d, k, c);
}
