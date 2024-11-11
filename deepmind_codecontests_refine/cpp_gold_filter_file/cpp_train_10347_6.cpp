#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  string A, B;
  cin >> A >> B;
  int s1 = 0, a1 = 0, b1 = 0, s0 = 0;
  for (int i = 0; i < 2 * n; ++i) {
    if (A[i] == '1' && B[i] == '1')
      ++s1;
    else if (A[i] == '1')
      ++a1;
    else if (B[i] == '1')
      ++b1;
    else
      ++s0;
  }
  s1 %= 2;
  if (s1 & 1) {
    if (b1) {
      s1 = 0;
      --b1;
    } else {
      printf("First\n");
      return 0;
    }
  }
  int m1 = min(a1, b1);
  a1 -= m1;
  b1 -= m1;
  if (a1)
    printf("First\n");
  else if (b1 >= 2)
    printf("Second\n");
  else
    printf("Draw\n");
  return 0;
}
