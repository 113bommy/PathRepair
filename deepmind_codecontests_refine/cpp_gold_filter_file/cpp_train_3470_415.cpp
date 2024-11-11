#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
void solve() {
  bool flag = 0, flag1 = 0;
  long long m, n, k, l, r, sum = 0, ans = 0, pos, pos1, c1 = 0, c2 = 0, c3 = 0,
                           c4 = 0, x, y, z, cnt = 0, mx = LLONG_MIN,
                           mn = LLONG_MAX;
  string s, t, s1, s2;
  string str = "";
  vector<int> v;
  cin >> n;
  switch (n) {
    case 1:
      cout << 2;
      break;
    case 2:
      cout << 3;
      break;
    case 3:
      cout << 1;
      break;
    case 4:
      cout << 2;
      break;
    case 5:
      cout << 1;
      break;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  bool notc = 0;
  int t = 1;
  if (notc) {
    cin >> t;
  }
  while (t--) {
    solve();
  }
  return 0;
}
