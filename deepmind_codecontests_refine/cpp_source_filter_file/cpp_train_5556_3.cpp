#include <bits/stdc++.h>
using namespace std;
int calc(const string &str) {
  int m = 0, p = 0;
  for (char c : str) {
    if (c == '+') {
      ++p;
      if (m > 0) --m;
    } else {
      ++m;
      if (p > 0) --p;
    }
  }
  return max(m, p);
}
void solve(istream &in, ostream &out) {
  string str;
  in >> str;
  out << calc(str) << endl;
}
int main() {
  solve(cin, cout);
  return 0;
}
