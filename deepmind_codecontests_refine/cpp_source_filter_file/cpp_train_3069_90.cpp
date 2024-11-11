#include <bits/stdc++.h>
using namespace std;
bool fmjj(const pair<long long, pair<long long, long long>> a,
          const pair<long long, pair<long long, long long>> b) {
  if (a.first == b.first) {
    return a.second.first < b.second.first;
  } else
    return a.first > b.first;
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long aa[10][10];
int main(void) {
  long long a, b, n, c = 0, x, y;
  map<char, long long> z;
  string s;
  for (long long i = 1; i <= 8; i++) {
    cin >> s;
    for (char x : s) z[x]++;
  }
  a = z['Q'] * 9 + z['R'] * 5 + z['B'] * 3 + z['K'] * 3 + z['P'];
  b = z['q'] * 9 + z['r'] * 5 + z['b'] * 3 + z['k'] * 3 + z['p'];
  if (a > b)
    cout << "White" << endl;
  else if (b > a)
    cout << "Black" << endl;
  else
    cout << "Draw" << endl;
}
