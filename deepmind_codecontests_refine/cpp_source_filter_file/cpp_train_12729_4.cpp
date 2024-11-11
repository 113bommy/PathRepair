#include <bits/stdc++.h>
using namespace std;
int main() {
  string p, q, r, str;
  cin >> p >> q >> r;
  str = p + q;
  sort(str.begin(), str.end());
  sort(r.begin(), r.end());
  if (str == r)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
