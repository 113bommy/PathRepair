#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    int a[n];
    for (int j = 0; j < n; j++) {
      a[j] = 0;
    }
    for (int j = 0; j < n; j++) {
      int k;
      cin >> k;
      if ((k + j) % n < 0) {
        a[(k + j) % n + n]++;
      } else {
        a[(k + j) % n]++;
      }
    }
    int c = 0;
    for (int j = 0; j < n; j++) {
      if (a[j] != 1) {
        c++;
      }
    }
    if (c == 0) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
