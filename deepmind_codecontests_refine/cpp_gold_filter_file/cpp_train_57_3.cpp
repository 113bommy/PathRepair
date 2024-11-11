#include <bits/stdc++.h>
using namespace std;
int n;
string a, b, c, d;
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> a >> b >> n;
  cout << a << ' ' << b << '\n';
  for (int i = 0; i < n; ++i) {
    cin >> c >> d;
    if (a == c)
      cout << d << ' ' << b, a = d;
    else
      cout << d << ' ' << a, b = d;
    cout << '\n';
  }
  return 0;
}
