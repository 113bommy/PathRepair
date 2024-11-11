#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i, j, k, m, l, n, a, b, c, d, e, f, g, x, y, z;
  long long cnt = 0, ans = 0, ans1 = 0, ans2 = 0, sum = 0, ca = 1, ar[1000],
            ar1[100] = {};
  string s, t, ss = "", tt = "";
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a;
    if (a % 2 == 0)
      cout << 4 * a + 1 << " ";
    else if (a % 4 == 1)
      cout << 2 * n + 1 << " ";
    else
      cout << a << " ";
  }
  cout << endl;
  return 0;
}
