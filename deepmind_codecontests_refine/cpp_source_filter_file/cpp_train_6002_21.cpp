#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int k = n * (n + 1) / 2;
  int p;
  p = m % k;
  int i, j;
  for (i = 1; i < n; i++) {
    p = p - i;
    if (p < 0) {
      cout << p + i;
      break;
    }
    if (p == 0) {
      cout << "0";
      break;
    }
  }
}
