#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if (a + b > c && b + c > a && a + c > b) {
    puts("0");
    return 0;
  }
  int A = c - (a + b) + 1, B = a - (b + c) + 1, C = b - (a + c) + 1;
  if (A < 1) A = 1;
  if (B < 1) A = 1;
  if (C < 1) A = 1;
  cout << max(A, max(B, C));
}
