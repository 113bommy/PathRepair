#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const long long mod = 1e9 + 7;
const int alphabet = 26;
const int inf = INT_MAX;
const long long linf = 1e18 + 9;
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
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long i, j, k, m, n;
  cin >> n >> k;
  if (k >= n * (n - 1) / 2) {
    cout << "no solution";
    return 0;
  }
  long long y = inf;
  for (i = 0; i < n; i++) {
    cout << "0 " << y << "\n";
    y--;
  }
  return 0;
}
