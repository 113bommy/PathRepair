#include <bits/stdc++.h>
using namespace std;
const long long INF = INT_MAX;
const long long N = 2e5 + 5;
int n, mn = INF, ans;
string s, a = "ACTG";
int main() {
  ios_base::sync_with_stdio(false), cin.tie(), cout.tie();
  cin >> n >> s;
  for (int i = 0; i < n - 3; i++) {
    for (int j = 0; j < 4; j++) {
      int x = (int)a[j];
      int y = (int)s[i + j];
      int a = abs(y - x);
      int b = 90 - y + (x - 65 + 1);
      int c = (y - 65) + (90 - x) + 1;
      ans += min(a, min(b, c));
    }
    mn = min(mn, ans);
    ans = 0;
  }
  cout << mn;
}
