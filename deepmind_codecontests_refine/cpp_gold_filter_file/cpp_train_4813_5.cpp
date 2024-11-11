#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int a, b, c;
  cin >> a >> b >> c;
  long long int ans = 1e18;
  long long int A = -1, B = -1, C = -1;
  for (long long int i = 1; i < 11000; i++) {
    long long int loc = abs(b - i);
    long long int x, y, z;
    y = i;
    vector<long long int> div;
    for (long long int j = 1; j * j <= i; j++) {
      if (i % j == 0) {
        div.emplace_back(j);
        div.emplace_back(i / j);
      }
    }
    long long int temp = 1e18;
    for (auto d : div) {
      if (temp > abs(d - a)) {
        temp = abs(d - a);
        x = d;
      }
    }
    loc += temp;
    temp = 1e18;
    if (c <= i) {
      temp = abs(c - i);
      z = i;
    } else {
      long long int e = c - c % i;
      temp = abs(e - c);
      z = e;
      e += i;
      if (abs(e - c) < temp) {
        temp = abs(e - c);
        z = e;
      }
    }
    loc += temp;
    if (loc < ans) {
      ans = loc;
      A = x;
      B = y;
      C = z;
    }
  }
  cout << ans << endl;
  cout << A << " " << B << " " << C << " " << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
