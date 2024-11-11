#include <bits/stdc++.h>
using namespace std;
const int N = 500 + 7;
const long long INF = 2e18 + 7;
const double EPS = 1e-15;
const int P = 37;
const long long MOD = 1e9 + 7;
int fx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int fy[] = {0, 0, 1, -1, -1, 1, -1, 1};
int main() {
  int n;
  string s;
  int b = 0, r = 0, g = 0;
  cin >> n >> s;
  for (int i = 0; i < n; i++)
    if (s[i] == 'B')
      b++;
    else if (s[i] == 'R')
      r++;
    else
      g++;
  if (g == n || b == n || r == n) return cout << s[0], 0;
  if (n == 1) return cout << s[0], 0;
  if (n == 2) {
    if (r > 0 && g > 0) cout << "B";
    if (r > 0 && b > 0) cout << "G";
    if (b > 0 && g > 0) cout << "R";
  }
  if (n == 3) {
    if (r > 0 && g > 0 && b > 0) return cout << "BGR", 0;
    if (r == 1 && b > 0) return cout << "GR", 0;
    if (r == 1 && g > 0) return cout << "BR", 0;
    if (b == 1 && r > 0) return cout << "BG", 0;
    if (b == 1 && g > 0) return cout << "BR", 0;
    if (g == 1 && r > 0) return cout << "BG", 0;
    if (g == 1 && b > 0) return cout << "GR", 0;
    cout << "BGR";
  }
  return 0;
}
