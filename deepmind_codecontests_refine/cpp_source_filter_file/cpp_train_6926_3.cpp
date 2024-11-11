#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int N = 4e5 + 10;
const int INF = 1000000000;
const double inf = 1e15;
const double eps = 1e-9;
string s, dig;
bool isDigit(char c) { return c >= '0' && c <= '9'; }
long long toInt(string s) {
  long long ret = 0;
  for (int(i) = (0); (i) < ((int)s.size()); ++(i)) ret = ret * 10 + s[i] - '0';
  return ret;
}
long long comb(long long n, string &s) {
  for (int(i) = (0); (i) < ((int)s.size()); ++(i)) n = n * 10 + s[i] - '0';
  return n;
}
long long get(string dig) {
  if ((int)dig.size() == 1) {
    for (int(i) = (1986); (i) < (2016); ++(i)) {
      if ((i % 10) == (dig[0] - '0')) {
        return i;
      }
    }
  }
  long long n = get(dig.substr(1));
  for (int i = 0;; i++) {
    long long val = comb(i, dig);
    if (i == 0 && dig[0] == '0') continue;
    if (val > n) {
      return val;
    }
  }
}
long long solve(string dig) { return get(dig); }
int main() {
  ios ::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int(i) = (0); (i) < (n); ++(i)) {
    cin >> s;
    dig = "";
    for (int(j) = (0); (j) < ((int)s.size()); ++(j))
      if (isDigit(s[j])) dig += s[j];
    cout << solve(dig) << endl;
  }
  return 0;
}
