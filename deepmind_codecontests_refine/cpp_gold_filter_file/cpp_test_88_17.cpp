#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int ar[n];
  for (int i = 0; i < n; i++) cin >> ar[i];
  if (n % 2 == 0)
    cout << "YES" << endl;
  else {
    int flag = 0;
    for (int i = 0; i < n - 1; i++) {
      if (ar[i] >= ar[i + 1]) flag++;
    }
    if (flag == 0)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
