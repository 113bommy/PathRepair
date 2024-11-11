#include <bits/stdc++.h>
using namespace std;
int main() {
  int d, n;
  cin >> d >> n;
  int a[n];
  int s = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i > 0 && i != n - 1) s += d - a[i];
  }
  cout << s;
}
