#include <bits/stdc++.h>
int a[101][101];
int ar[101];
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int f = 0; f < n; f++) {
      cin >> a[i][f];
    }
  }
  for (int i = 0; i < n; i++) {
    int f = i;
    int cur = 0;
    for (f = 0; f < n; f++) {
      if (i != f) {
        cur |= a[i][f];
      }
    }
    ar[i] = cur;
  }
  for (int i = 0; i < n; i++) {
    cout << ar[i] << " ";
  }
  return 0;
}
