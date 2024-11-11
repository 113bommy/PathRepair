#include <bits/stdc++.h>
using namespace std;
inline bool isvowel(char c) {
  c = tolower(c);
  if (c == 'a' || c == 'e' || c == 'i' || c == 'y' || c == 'o' || c == 'u')
    return 1;
  return 0;
}
const double eps = 0.000001;
const long double pi = acos(-1);
const int maxn = 1e7 + 9;
const int mod = 1e9 + 1;
const long long MOD = 1e18 + 9;
const long long INF = 1e18 + 123;
const int inf = 2e9 + 11;
const int mxn = 1e6 + 9;
const int N = 6e5 + 123;
const int M = 22;
const int pri = 997;
const int Magic = 2101;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
int n, l, r;
int main() {
  cin >> n;
  cout << "0 0\n";
  string s;
  cin >> s;
  l = 1, r = 1e9;
  for (long long i = 2; i <= n; i++) {
    int md = (l + r) >> 1;
    cout << md << " 0\n";
    string cur;
    cin >> cur;
    if (s != cur)
      r = md;
    else
      l = md + 1;
  }
  cout << r << " 1 " << r + 1 << " 3\n";
  return 0;
}
