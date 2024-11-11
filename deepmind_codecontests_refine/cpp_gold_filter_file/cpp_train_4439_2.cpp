#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const long long INF = 1000000000000000000;
const long double PI = 4 * atan((long double)1);
string s;
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  ;
  cin >> s;
  long long zeroCount = 0;
  for (int i = s.size() - 1; i >= 0; i--) {
    if (s.at(i) == '0') {
      zeroCount++;
    }
    if (s.at(i) == '1' && zeroCount >= 6) {
      cout << "yes";
      return 0;
    }
  }
  cout << "no";
  return 0;
}
