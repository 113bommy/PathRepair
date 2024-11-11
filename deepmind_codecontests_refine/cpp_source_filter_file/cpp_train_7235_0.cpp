#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n], c = 0;
  for (int i = 0; i < n; ++i) cin >> a[i];
  c += abs(a[0]);
  for (int i = 1; i < n; ++i) {
    c += abs(a[i - 1] - a[i]);
  }
  cout << c << '\n';
  return 0;
}
