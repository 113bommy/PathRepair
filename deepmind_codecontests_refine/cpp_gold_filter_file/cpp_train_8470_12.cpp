#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, n;
int cek(int x) {
  d = x % 10;
  c = ((x % 100) - d) / 10;
  b = ((x % 1000) - (x % 100)) / 100;
  a = ((x % 10000) - (x % 1000)) / 1000;
  if (a != b && a != c && a != d && b != c && b != d && c != d)
    return x;
  else
    return 0;
}
int main() {
  cin >> n;
  for (int i = n + 1; i <= 9999; i++) {
    if (cek(i) != 0) {
      cout << i;
      break;
    }
  }
}
