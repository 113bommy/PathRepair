#include <bits/stdc++.h>
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using namespace std;
inline int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
inline int lcm(int a, int b) { return (a * b) / gcd(a, b); }
int main(int argc, char** argv) {
  ios_base::sync_with_stdio(false);
  cout.setf(ios::fixed);
  cout.precision(20);
  ostream_iterator<int> o_it(cout, ",");
  int n;
  cin >> n;
  if (n % 2 == 1)
    cout << (n >> 1) << endl;
  else
    cout << ((n - 1) >> 1) << endl;
};
