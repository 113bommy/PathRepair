#include <bits/stdc++.h>
using namespace std;
int m, n;
int main() {
  cin >> m >> n;
  m -= n;
  if (m == 0 || n == 0)
    cout << 0 << " " << 0 << endl;
  else
    cout << 1 << " " << min(m, n + 1) << endl;
  return 0;
}
