#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, a[100], max = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    k += a[i];
    if (a[i] > max) max = a[i];
  }
  cout << (max * n) - k;
}
