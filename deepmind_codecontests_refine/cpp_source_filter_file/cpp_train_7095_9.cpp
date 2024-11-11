#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  int flag = 0;
  for (int i = a, j = c;; i++, j--) {
    if (j <= 0) j += n;
    if (i >= n) i -= n;
    if (i == j) flag = 1;
    if (i == b || j == d) break;
  }
  if (flag)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
