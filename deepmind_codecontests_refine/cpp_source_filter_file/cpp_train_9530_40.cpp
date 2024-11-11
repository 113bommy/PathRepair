#include <bits/stdc++.h>
using namespace std;
const long N = 100000, mx = 1000000000;
long long i, m, n, k, l, w, j, l1, l2, a, b, p, q, nn;
string s;
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> s >> nn >> m;
    if ((nn > 2400) && (m > nn)) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
}
