#include <bits/stdc++.h>
using namespace std;
struct toado {
  int x, y;
};
long long n;
long long x, y, z;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  if (n <= 2) {
    cout << -1;
    return 0;
  }
  x = n;
  y = x + 1;
  z = x * y;
  cout << x << " " << y << " " << z;
  return 0;
}
