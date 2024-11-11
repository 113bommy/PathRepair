#include <bits/stdc++.h>
using namespace std;
int n, us[60];
void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (us[x] == 0) {
      cout << x << " ";
      us[x] = 1;
    } else
      us[x] = 0;
  }
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << endl;
  }
}
