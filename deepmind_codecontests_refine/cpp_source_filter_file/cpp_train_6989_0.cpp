#include <bits/stdc++.h>
using namespace std;
const int MX = 2e9;
const long long MX2 = 1e18;
const double pi = acos(-1);
int ans[2000] = {};
long long find_answer() {
  long long res = 0;
  long long cur = 0;
  int k = -1;
  for (int i = 0; i < 2000; i++) {
    cur = cur + ans[i];
    if (cur < 0) {
      cur = 0;
      k = i;
    }
    res = max(res, (i - k) * cur);
  }
  return res;
}
int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);
  int k;
  cin >> k;
  int a, b, c, i;
  k += 2000;
  a = k / 1997;
  ans[0] = -1;
  ans[1] = k - a * 1998;
  for (i = 2; i < 2000; i++) ans[i] = a;
  cout << 2000 << '\n';
  for (int x : ans) cout << x << ' ';
  return 0;
}
