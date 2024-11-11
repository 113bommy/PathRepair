#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, beg, end, l, r;
  cin >> n >> m >> beg >> end;
  l = beg / m;
  r = end / m;
  if (beg % m == 0) l--;
  if (end % m == 0) r--;
  if (beg % m == 1 && end % m == 0 || beg == 1 && end == n ||
      end == n && beg % m == 1 || r == l || m == 1 || m == n)
    cout << 1 << endl;
  else if (r - l == 1 || (end % m + (m - (beg % m - 1))) == m && beg % m != 0 ||
           (end % m + 1 == m) && beg % m == 0 || end == n || beg == 1 ||
           end % m == 0 || beg % m == 1)
    cout << 2 << endl;
  else
    cout << 3 << endl;
  return 0;
}
