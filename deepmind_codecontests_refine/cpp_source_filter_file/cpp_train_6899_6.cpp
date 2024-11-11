#include <bits/stdc++.h>
bool flag = true;
using namespace std;
const double epsilon = 0.0000001f;
const double PI = 3.141592653589793238460;
const long long int cons = 1e5 + 1;
const long long int inf = 998244353;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int T = 1, te = 1;
  while (T--) {
    long long int i = 0, j = 0, ans = 0, x = 0, y = 0, z = 0;
    long long int n, k = 0, m = 0, mn = INT_MAX, mx = INT_MIN;
    string s, rev;
    cin >> s;
    reverse(s.begin(), s.end());
    if (s == rev) {
      cout << 0 << endl;
      continue;
    }
    n = s.size();
    cout << 3 << endl;
    cout << 'R' << " " << n - 1 << endl;
    cout << 'L' << " " << n - 1 << endl;
    cout << 'L' << " " << 2 << endl;
  }
  return 0;
}
