#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d, c = 0;
  cin >> d >> n;
  int a[n], i;
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 1; i < n - 1; i++) {
    c += d - a[i];
  }
  cout << c;
}
