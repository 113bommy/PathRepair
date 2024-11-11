#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x, y, n;
  cin >> n >> x >> y;
  if ((x != n / 2 && x != n / 2 + 1) || (y != n / 2 && y != n / 2 + 1))
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
