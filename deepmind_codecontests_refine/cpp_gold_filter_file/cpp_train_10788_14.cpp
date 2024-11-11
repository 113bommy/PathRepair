#include <bits/stdc++.h>
using namespace std;
void code() {
  long long n;
  cin >> n;
  long long yr = 0;
  long long yl = 0;
  while (n--) {
    long long x, y;
    cin >> x >> y;
    if ((x < 0 and y <= 0) or (x < 0 and y >= 0)) {
      yl++;
    } else {
      yr++;
    }
  }
  if (yl <= 1 or yr <= 1) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
signed main() { code(); }
