#include <bits/stdc++.h>
using namespace std;
int min(int, int, int);
int main() {
  int X1, X2, X3;
  cin >> X1 >> X2 >> X3;
  int D1 = abs(X1 - X2) + abs(X1 - X3);
  int D2 = abs(X2 - X1) + abs(X2 - X3);
  int D3 = abs(X3 - X1) + abs(X3 - X2);
  cout << min(D1, D2, D3) << endl;
  return 0;
}
int min(int a, int b, int c) {
  int m = a;
  if (b < a) m = b;
  if (c < a) m = c;
  return m;
}
