#include <bits/stdc++.h>
using namespace std;
int pole[112345];
pair<int, int> dva[112345];
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> pole[i];
  }
  sort(pole, pole + n);
  int k = (n - 1) / 2;
  int l = 0;
  while (k + l >= 0 and k + l < n) {
    cout << pole[k + l] << " ";
    if (l <= 0) l--;
    l *= (-1);
  }
  cout << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
