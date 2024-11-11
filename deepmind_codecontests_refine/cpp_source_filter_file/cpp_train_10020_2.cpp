#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, x;
  cin >> n >> x;
  int tmp1, tmp2, cnt = 0;
  for (int i = 0; i < n; i++) {
    cin >> tmp1 >> tmp2;
    if (tmp1 == x || tmp2 == x) cnt++;
  }
  if (cnt < 2) {
    cout << "Ayush\n";
  } else {
    if (n % 2 == 0)
      cout << "Ayush\n";
    else
      cout << "Ashish\n";
  }
  return;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
  return 0;
}
