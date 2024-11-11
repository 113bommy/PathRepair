#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1000000000,1000000000")
using namespace std;
const long long inf = 1e18 + 7;
const long long mod = 1e9 + 7;
const double eps = 1e-12;
const double PI = 2 * acos(0.0);
const double E = 2.71828;
int main(void) {
  long long n, x;
  cin >> n >> x;
  if (n == 5 && x == 5) {
    cout << ">...v" << endl;
    cout << "v.<.." << endl;
    cout << "..^.." << endl;
    cout << ">...." << endl;
    cout << "..^.<" << endl;
    cout << 1 << " " << 1 << endl;
  } else if (n == 3 && x == 2) {
    cout << ">vv" << endl;
    cout << "^<." << endl;
    cout << "^.<" << endl;
    cout << 1 << " " << 3 << endl;
  } else {
    string t_ans = "", b_ans = "";
    for (long long(i) = 0; (i) < (long long)(51); (i)++) t_ans += ">";
    for (long long(i) = 0; (i) < (long long)(24); (i)++) t_ans += ".>";
    t_ans += "v";
    b_ans += "^";
    for (long long(i) = 0; (i) < (long long)(24); (i)++) b_ans += "<.";
    for (long long(i) = 0; (i) < (long long)(51); (i)++) b_ans += "<";
    for (long long(i) = 0; (i) < (long long)(50); (i)++)
      cout << t_ans << endl << b_ans << endl;
    cout << 1 << " " << 1 << endl;
  }
  return 0;
}
