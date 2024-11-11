#include <bits/stdc++.h>
using namespace std;
long long a[200005], b[200005];
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  long long _, a, b, c;
  cin >> _;
  while (_--) {
    cin >> a >> b >> c;
    if (c > a)
      cout << "1 ";
    else
      cout << "-1 ";
    if (b * a > c)
      cout << b << '\n';
    else
      cout << "-1" << '\n';
  }
}
