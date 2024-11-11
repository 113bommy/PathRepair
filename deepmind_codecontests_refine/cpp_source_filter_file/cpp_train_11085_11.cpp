#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c = 0, c2 = 0, c3 = 0, max = 0;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 1) {
      c++;
    }
    if (a[i] == 2) {
      c2++;
    }
    if (a[i] == 3) {
      c3++;
    }
  }
  int p[] = {c, c2, c3};
  for (int i = 0; i < n; i++) {
    if (p[i] > max) {
      max = p[i];
    }
  }
  cout << n - max;
}
