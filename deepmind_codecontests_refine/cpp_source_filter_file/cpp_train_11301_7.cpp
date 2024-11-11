#include <bits/stdc++.h>
using namespace std;
int main() {
  long long l1, r1, l2, r2, k, l, r;
  cin >> l1 >> r1 >> l2 >> r2 >> k;
  l = max(l1, l2);
  r = min(r1, r2);
  if (r1 < l2)
    cout << "0";
  else if (k >= l && k <= r)
    cout << r - l;
  else
    cout << r - l + 1;
  return 0;
}
