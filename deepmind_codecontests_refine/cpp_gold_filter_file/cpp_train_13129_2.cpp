#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18 + 111;
const int maxn = 2e5 + 10;
const int maxq = 1e6 + 10;
const int alf = 26;
const int dlm = 1e9 + 7;
const int del = 10001;
const int manfi = 1e5;
string O[] = {"Yes", "No", "YES", "NO", "IMPOSSIBLE"};
int ON = 0;
vector<long long> st[10];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    int n, x, y, d;
    cin >> n >> x >> y >> d;
    if (x % d == y % d) {
      cout << abs(x - y) / d;
    } else {
      if (1 == n % d && 1 == y % d) {
        int a = (x - 1) / d + (((x - 1) % d) > 0);
        int b = (n - x) / d + (((n - x) % d) > 0);
        cout << min(a + abs(y - 1) / d, b + abs(y - n) / d);
      } else if (y % d == 1) {
        int a = (x - 1) / d + (((x - 1) % d) > 0);
        cout << a + abs(y - 1) / d;
      } else if (y % d == n % d) {
        int b = (n - x) / d + (((n - x) % d) > 0);
        cout << b + abs(y - n) / d;
      } else {
        cout << -1;
      }
    }
    cout << '\n';
  }
  return 0;
}
