#include <bits/stdc++.h>
using namespace std;
string toString(long long n) {
  ostringstream os;
  os << n;
  return os.str();
}
long long solve(string s) {
  string rs = s;
  for (int i = 0; i < s.size(); ++i) rs[i] = '0' + '9' - s[i];
  long long a, b;
  {
    istringstream sin(s);
    sin >> a;
  }
  {
    istringstream sin(rs);
    sin >> b;
  }
  return a * b;
}
const long long MAX = 1000000000;
int main() {
  long long l, r;
  long long ret;
  cin >> l >> r;
  if (r == MAX) {
    cout << MAX * (8999999999LL) << "\n";
    return 0;
  }
  string A = toString(l);
  string B = toString(r);
  if (A.size() != B.size()) {
    A = "1" + string(A.size() - 1, '0');
  }
  string mid = "4" + string(A.size() - 1, '9');
  if (B <= mid) {
    cout << solve(B) << endl;
  } else if (A >= mid) {
    cout << solve(A) << endl;
  } else {
    cout << solve(mid) << endl;
  }
}
