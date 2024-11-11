#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
template <class _T>
inline string tostr(const _T& a) {
  ostringstream os("");
  os << a;
  return os.str();
}
const long double PI = 3.1415926535897932384626433832795;
const long double EPS = 1e-9;
int n, a[1200], x;
string s;
int main() {
  cout.flags(ios::fixed);
  cout.precision(2);
  for (int i = 0; i < 5; i++) cin >> a[i];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    if (s == "S") x = 0;
    if (s == "M") x = 1;
    if (s == "L") x = 2;
    if (s == "XL") x = 3;
    if (s == "XXL") x = 4;
    int bst = 20, z;
    for (int j = 0; j < 5; j++) {
      if (a[j]) {
        if (abs(j - x) <= bst) {
          bst = abs(j - x);
          z = j;
        }
      }
    }
    a[z]--;
    if (z == 0) cout << "S" << endl;
    if (z == 1) cout << "M" << endl;
    if (z == 2) cout << "L" << endl;
    if (z == 3) cout << "XL" << endl;
    if (z == 4) cout << "XXL" << endl;
  }
  return 0;
}
