#include <bits/stdc++.h>
using namespace std;
const int fx[] = {+1, -1, +0, +0}, fy[] = {+0, +0, +1, -1};
const long long mod = 1e9 + 7, INF = 1e18, mx = 1e6;
int Case = 1, cas = 0;
int main() {
  ios_base ::sync_with_stdio(0), cin.tie(0);
  ;
  int n, x;
  cin >> n >> x;
  if (n == 1)
    cout << "YES" << endl << x << endl;
  else if (n == 2 && x == 0)
    cout << "NO" << endl;
  else if (n == 2)
    cout << "YES" << 0 << " " << x << endl;
  else {
    cout << "YES" << endl;
    int P = 0;
    for (int i = 1; i <= n - 3; i++) {
      cout << i << " ";
      P ^= i;
    }
    int a = (1 << 17);
    int b = (1 << 18);
    if (P == x)
      cout << a << " " << b << " " << (a + b) << endl;
    else
      cout << 0 << " " << a << " " << ((a ^ P) ^ x) << endl;
  }
  return 0;
}
