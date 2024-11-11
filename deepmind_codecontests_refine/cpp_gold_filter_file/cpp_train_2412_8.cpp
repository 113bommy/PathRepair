#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long r;
  cin >> r;
  if (r < 5 || r % 2 == 0)
    cout << "NO";
  else
    cout << 1 << " " << (r - 3) / 2;
}
