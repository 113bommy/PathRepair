#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const long long mod = 1e9 + 7;
const int alphabet = 26;
const int inf = INT_MAX;
const long long linf = 1e18 + 9;
namespace util {
inline long long cnm(char ch) { return (ch - '0'); }
inline long long cap(char ch) { return (ch - 'a'); }
inline void instr(string& s, long long& n) {
  cin >> s;
  n = s.length();
}
inline void instr(string& s) { cin >> s; }
template <typename T>
T gcd(T a, T b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
template <typename T>
bool min(T a, T b, T c) {
  return std::min(a, std::min(b, c));
}
}  // namespace util
using namespace util;
void solve() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long i, j, k, m, n;
  string s;
  instr(s, n);
  bool vert = false, horz = false;
  for (auto x : s) {
    if (x == '0') {
      if (vert)
        cout << "3 4"
             << "\n";
      else
        cout << "1 4"
             << "\n";
      vert = !vert;
    } else {
      if (horz)
        cout << "4 3"
             << "\n";
      else
        cout << "4 1"
             << "\n";
      horz = !horz;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
