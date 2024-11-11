#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int a[1005];
int main() {
  int x, y, n;
  cin >> x >> y;
  int a[10] = {-x, -y, x - y, x, y, y - x};
  cin >> n;
  int ans = (n + 2) % 6;
  a[ans] %= mod;
  if (a[ans] < 0) a[ans] += mod;
  cout << a[ans] << endl;
  return 0;
}
