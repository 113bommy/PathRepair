#include <bits/stdc++.h>
using namespace std;
inline bool setmin(int &x, int y) { return (y < x) ? x = y, 1 : 0; }
inline bool setmax(int &x, int y) { return (y > x) ? x = y, 1 : 0; }
inline bool setmin(long long &x, long long y) { return (y < x) ? x = y, 1 : 0; }
inline bool setmax(long long &x, long long y) { return (y > x) ? x = y, 1 : 0; }
const int N = 100000;
const int inf = (int)1e9 + 1;
const long long big = (long long)1e18 + 1;
const int P = 239;
const int P1 = 31;
const int P2 = 57;
const int MOD = (int)1e9 + 7;
const int MOD1 = (int)1e9 + 9;
const int MOD2 = 998244353;
const double eps = 1e-9;
const double pi = atan2(0, -1);
const int ABC = 26;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.precision(20);
  cout << fixed;
  for (int i = 0; i <= 8; i++) {
    cout << i << "??"
         << "<>" << i + 1 << "\n";
  }
  cout << "9??"
       << "<>"
       << "??0"
       << "\n";
  cout << "??"
       << "<>1"
       << "\n";
  for (int i = 0; i <= 9; i++) {
    cout << "?" << i << ">>" << i << "?"
         << "\n";
  }
  for (int i = 0; i <= 8; i++) {
    cout << i << "?"
         << "<>" << i + 1 << "\n";
  }
  cout << "9?>>??0"
       << "\n";
  for (int i = 0; i <= 9; i++) {
    cout << i << ">>"
         << "?" << i << "\n";
  }
  return 0;
}
