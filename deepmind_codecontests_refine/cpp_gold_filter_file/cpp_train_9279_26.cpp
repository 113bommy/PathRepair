#include <bits/stdc++.h>
using namespace std;
template <typename T>
string tostr(const T& t) {
  ostringstream os;
  os << t;
  return os.str();
}
long long big = 10000000;
long long N, X, Y;
int main() {
  cin >> N >> X >> Y;
  long long cur = 1;
  bool ok = false;
  while (1) {
    if (cur + (N - 1) > Y) {
      break;
    }
    if (cur * cur + (N - 1) >= X) {
      for (int i = (int)(0); i <= (int)(N - 1 - 1); ++i) cout << "1" << endl;
      cout << cur << endl;
      ok = true;
      break;
    }
    ++cur;
  }
  if (!ok) cout << "-1" << endl;
  return 0;
}
