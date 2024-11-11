#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  long long int a[50007];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (a[0] + a[1] <= a[n - 1]) {
    cout << 1 << " " << 2 << " " << n << endl;
  } else
    cout << -1 << endl;
}
int main() {
  long long int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
}
