#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int maxx = 0;
  for (int i = 0; i < n; i++) {
    int ee = 0;
    for (int j = 0; j < i; j++) {
      ee += a[j];
    }
    for (int j = i; j < n; j++) {
      ee += 1 - a[j];
      int e = 0;
      for (int jj = j + 1; jj < n; jj++) {
        e += a[jj];
      }
      if (e + ee > maxx) maxx = e + ee;
    }
  }
  cout << maxx;
  return 0;
}
