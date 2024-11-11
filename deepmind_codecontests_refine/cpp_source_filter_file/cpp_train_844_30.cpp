#include <bits/stdc++.h>
using namespace std;
int fx[4] = {1, -1, 0, 0};
int fy[4] = {0, 0, 1, -1};
const double PI = acos(-1.0);
const double EPS = 1e-6;
const int MOD = (int)1e9 + 7;
const int maxn = (int)3e5 + 5;
const long long inf = 5e18 + 100;
void solve() {
  int n;
  cin >> n;
  int koybar = n / 5;
  int baki = n % 5;
  string s = "abcda";
  for (int i = 1; i <= koybar; i++) {
    cout << s;
  }
  for (int i = 0; i < baki; i++) {
    cout << s[i];
  }
  cout << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
