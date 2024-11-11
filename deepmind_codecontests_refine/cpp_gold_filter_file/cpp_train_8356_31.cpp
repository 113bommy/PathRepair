#include <bits/stdc++.h>
using namespace std;
const int nax = 2147483646;
const int mod = 998244353;
int grid[2010];
void solve() {
  int n;
  cin >> n;
  int a = 0;
  int b = 0;
  int c = 0;
  if (n == 1 || n == 4 || n == 2) {
    cout << -1 << "\n";
    return;
  }
  a = n / 3;
  if (n % 3 == 2) {
    b = 1;
    a -= 1;
  }
  if (n % 3 == 1) {
    c = 1;
    a -= 2;
  }
  cout << a << " " << b << " " << c << "\n";
  return;
}
int main() {
  int T;
  T = 1;
  scanf("%d", &T);
  while (T--) {
    solve();
  }
}
