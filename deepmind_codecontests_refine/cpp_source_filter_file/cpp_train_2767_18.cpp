#include <bits/stdc++.h>
using namespace std;
int a[2];
int main() {
  int n, x;
  cin >> n >> x;
  n = n % 6;
  a[x] = 1;
  while (n > 0) {
    if (n % 2 == 0) {
      swap(a[1], a[2]);
    } else
      swap(a[0], a[1]);
    n--;
  }
  for (int i = 0; i <= 2; i++) {
    if (a[i] == 1) {
      cout << i;
      break;
    }
  }
  return 0;
}
