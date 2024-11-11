#include <bits/stdc++.h>
using namespace std;
const long long M{1000000007};
long long p(int n) {
  long long r{1};
  while (n--) (r <<= 1) %= M;
  return r;
}
long long f(const string& s, int i) {
  long long add{s[i] == '1' ? p(2 * (s.size() - i) - 2) : 0};
  return add + (++i < s.size() ? 2 * f(s, i) : 0);
}
int main() {
  string s;
  cin >> s;
  cout << f(s, 0);
}
