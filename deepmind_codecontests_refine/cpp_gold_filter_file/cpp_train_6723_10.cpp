#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  unsigned long long a, b;
  cin >> a >> b;
  if (a < b || (a - b) % 2 != 0) {
    cout << -1 << endl;
    return 0;
  }
  long long x = (a - b) / 2, y = a - x;
  if ((x ^ y) != b)
    cout << -1 << endl;
  else
    cout << x << ' ' << y << endl;
}
