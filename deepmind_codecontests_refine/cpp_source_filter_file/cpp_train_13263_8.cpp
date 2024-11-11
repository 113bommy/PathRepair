#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int MAX = 2e5 + 5;
const long long MAX2 = 11;
const int MOD = 998244353;
const long long INF = 2e18;
const int dr[] = {1, 0, -1, 0, 1, 1, -1, -1, 0};
const int dc[] = {0, 1, 0, -1, 1, -1, 1, -1, 0};
const double pi = acos(-1);
const double EPS = 1e-9;
int x, y;
string s;
bool vis[10005], st;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> s;
  s.push_back(',');
  for (auto i : s) {
    if (i == ',')
      vis[x] = 1, x = 0;
    else
      x = x * 10 + i - '0';
  }
  x = 0;
  for (int i = 1; i <= 1000; i++) {
    if (vis[i]) {
      if (!x)
        x = i;
      else
        y = i;
    } else {
      if (!y) {
        if (x) {
          if (st) cout << ',';
          cout << x;
          st = 1;
        }
      } else {
        if (st) cout << ',';
        cout << x << "-" << y;
        st = 1;
      }
      x = y = 0;
    }
  }
  return 0;
}
