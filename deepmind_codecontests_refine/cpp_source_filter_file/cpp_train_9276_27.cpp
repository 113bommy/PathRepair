#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s, i, r, x, k;
  int a[102];
  cin >> n;
  k = n;
  while (n--) {
    cin >> r;
    while (r--) {
      cin >> x;
      ++a[x];
    }
  }
  for (i = 1; i <= 100; i++) {
    if (a[i] == k) {
      cout << i << " ";
    }
  }
  cout << endl;
  return 0;
}
