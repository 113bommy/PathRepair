#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int big = 0, small = 1000000000;
  int a[1000];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] > big) {
      big = a[i];
    } else if (a[i] < small) {
      small = a[i];
    }
  }
  cout << big - small + 1 - n;
}
