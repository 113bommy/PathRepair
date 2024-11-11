#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[101];
  cin >> n;
  for (int i = 1; i < n; i++) cin >> a[i];
  int x, y;
  cin >> x >> y;
  int tong = 0;
  for (int i = 1; i <= y - x; i++) tong += a[i];
  cout << tong;
}
