#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[] = {1, -1, 0, 0, -1, 1, 1, -1};
const double PI = acos(-1), EPS = 1e-7;
const int OO = 0x3f3f3f3f, N = 1e7 + 5, mod = 1e9 + 7;
using namespace std;
long long gcd(long long x, long long y) { return (!y) ? x : gcd(y, x % y); }
long long lcm(long long x, long long y) { return ((x / gcd(x, y)) * y); }
void file() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  file();
  string x[] = {"zero",    "one",       "two",      "three",    "four",
                "five",    "six",       "seven",    "eight",    "nine",
                "eleven",  "twelve",    "thirteen", "fourteen", "fifteen",
                "sixteen", "seventeen", "eighteen", "nineteen"};
  string y[] = {"ten",   "twenty",  "thirty", "forty", "fifty",
                "sixty", "seventy", "eighty", "ninety"};
  string n;
  cin >> n;
  int num = stoi(n);
  if (n.size() >= 2 && n[1] == '0') {
    cout << y[(n[0] - '0') - 1] << '\n';
  } else if (n.size() >= 2 && num < 20) {
    cout << x[num - 1] << '\n';
  } else if (n.size() < 2) {
    cout << x[(n[0] - '0')] << '\n';
  } else {
    cout << y[(n[0] - '0') - 1] << "-" << x[(n[0] - '0')] << '\n';
  }
  return 0;
}
