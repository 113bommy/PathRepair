#include <bits/stdc++.h>
using namespace std;
int n, t;
int main() {
  cin >> n >> t;
  long long z = pow(10, n - 2);
  if (n == 1 and t == 10) return cout << -1 << endl, 0;
  if (n == 1) return cout << t << endl, 0;
  if (t == 2 or t == 4 or t == 5 or t == 8 or t == 10) cout << 40;
  if (t == 7)
    cout << 14;
  else
    cout << 18;
  n -= 2;
  while (n) {
    cout << '0';
    n--;
  }
  cout << endl;
}
