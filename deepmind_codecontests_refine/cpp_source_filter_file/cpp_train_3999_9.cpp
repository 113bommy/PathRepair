#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  int pairs = 1;
  int q = a[0] % 10;
  for (int i = 1; i < n; i++) {
    int p = a[i] / 10;
    if (p == q) pairs++;
    q = p;
  }
  cout << pairs;
  return 0;
}
