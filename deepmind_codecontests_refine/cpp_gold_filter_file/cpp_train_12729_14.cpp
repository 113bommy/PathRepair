#include <bits/stdc++.h>
using namespace std;
int main() {
  string p, q, r, str;
  cin >> p >> q >> r;
  str = p + q;
  sort(str.begin(), str.end());
  sort(r.begin(), r.end());
  if (str == r)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
