#include <bits/stdc++.h>
const int MOD = 1e9 + 7;
const long long int INF = 2e18;
const int mxn = 2e9 + 9;
const int mxd = 2e5 + 5;
const int mxa = 1e5 + 5;
int64_t gcd(int64_t a, int64_t b) {
  if (b == 0LL) return a;
  return gcd(b, a % b);
}
int64_t lcm(int64_t a, int64_t b) { return (a / gcd(a, b) * b); }
using namespace std;
int64_t maxll(int64_t x, int64_t y) { return x > y ? x : y; }
int64_t minll(int64_t x, int64_t y) { return x < y ? x : y; }
void Run_Case() {
  int n, k;
  cin >> n >> k;
  string str;
  cin >> str;
  int f = 0;
  for (int i = 0; i < n; i++) {
    if (str[i] == '.') {
      str[i] = '0';
      if (i + k < n and str[i + k] == '0' or i - k >= 0 and str[i - k] == '0') {
        str[i] = '1';
      }
    }
    if (i + k < n and str[i] != str[i + k]) f = 1;
  }
  if (f)
    cout << str << '\n';
  else
    cout << "NO" << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T;
  T = 1;
  while (T--) {
    Run_Case();
  }
  return 0;
}
