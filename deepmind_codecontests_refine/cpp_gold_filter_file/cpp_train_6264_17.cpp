#include <bits/stdc++.h>
using namespace std;
void slv() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 1; i < n - 1; i++) {
    if (a[i] < a[i - 1] && a[i] < a[i + 1]) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tc = 1;
  while (tc--) {
    slv();
  }
  return 0;
}
