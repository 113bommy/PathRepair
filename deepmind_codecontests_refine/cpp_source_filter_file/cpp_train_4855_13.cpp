#include <bits/stdc++.h>
using namespace std;
bool borj(int n, int i) {
  int a = pow(2, ((double)i));
  int g = (a - 1) * a / 2;
  if (n % g == 0) return true;
  return false;
}
int main() {
  int n;
  int m = 0;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    if (borj(n, i) == true) {
      int a = pow(2, ((double)i));
      int g = (a - 1) * a / 2;
      if (m < g) m = g;
    }
  }
  cout << m;
  return 0;
}
