#include <bits/stdc++.h>
using namespace std;
const int MAXN = -1;
long long l, r, d, n;
int main() {
  int t;
  cin >> t;
  for (int cs = (0); cs < (int)(t); cs++) {
    cin >> n >> l >> r;
    d = n / l;
    cout << ((n <= d * r) ? "Yes" : "No") << endl;
  }
  return 0;
}
