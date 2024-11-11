#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[101];
  for (int i = 0; i < 101; i++) {
    a[i] = 0;
  }
  int n, p, b, ma = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p;
    for (int j = 0; j < p; j++) {
      cin >> b;
      if (b > ma) {
        ma = b;
      }
      a[b]++;
    }
  }
  for (int i = 1; i <= ma; i++) {
    if (a[i] == n) {
      cout << i << " ";
    }
  }
  return 0;
}
