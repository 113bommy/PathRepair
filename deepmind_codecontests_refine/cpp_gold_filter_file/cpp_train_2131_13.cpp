#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
void solve() {
  long long n;
  cin >> n;
  for (int i = n + 1; i < n + 20; i++) {
    int x = i;
    if (x < 0) {
      x = -x;
    }
    while (x != 0) {
      if (x % 10 == 8) {
        cout << i - n << endl;
        return;
      }
      x /= 10;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  for (int i = 1; i <= t; i++) {
    solve();
  }
}
