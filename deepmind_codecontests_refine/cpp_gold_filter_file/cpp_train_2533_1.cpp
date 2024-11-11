#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long i, j, k, l, n, m, len, ans, mx = -1, mn;
  string s;
  bool flag = false;
  ;
  cin >> n;
  int cnt = n;
  while (n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n % 7 == 0) {
    if (n % 2 == 0) {
      n = n / 2;
      cnt += n;
    } else if (n % 3 == 0) {
      n = n / 3;
      cnt += n;
    } else if (n % 5 == 0) {
      n = n / 5;
      cnt += n;
    } else if (n % 7 == 0) {
      n = n / 7;
      cnt += n;
    }
  }
  if (n == 1)
    cout << cnt << "\n";
  else
    cout << cnt + 1 << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  solve();
}
