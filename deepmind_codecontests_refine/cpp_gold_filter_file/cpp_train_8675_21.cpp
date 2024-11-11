#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
  int a = 1, b = 1, n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> s;
    if (s == "UL")
      ++a;
    else if (s == "UR")
      ++b;
    else if (s == "DL")
      ++b;
    else if (s == "DR")
      ++a;
    else {
      ++a;
      ++b;
    }
  }
  cout << ((long long)(a)) * b << endl;
  return 0;
}
