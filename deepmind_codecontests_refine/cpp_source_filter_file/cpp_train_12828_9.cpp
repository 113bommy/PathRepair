#include <bits/stdc++.h>
using namespace std;
int main() {
  int tt, qq;
  cin >> tt;
  for (qq = 1; qq <= tt; qq++) {
    long long n, x, y, a, b;
    cin >> n >> x >> y;
    cout << max(1LL, x + y + 1 - n) << " " << min(n, x + y - 1) << endl;
  }
}
