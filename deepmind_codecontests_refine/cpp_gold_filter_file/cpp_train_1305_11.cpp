#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  long long a, b, c;
  cin >> b >> a >> c;
  if (c == 0) {
    if (a == b)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
    return 0;
  }
  if ((a - b) * c >= 0 && (a - b) % c == 0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
