#include <bits/stdc++.h>
using namespace std;
long long int n, x, y;
int k, cnt;
int main() {
  cin >> n >> x >> y;
  n /= 2;
  if (x == n && (y == n || y == n + 1))
    cout << "NO" << endl;
  else if (x == n + 1 && (y == n || y == n + 1))
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
  return 0;
}
