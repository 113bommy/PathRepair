#include <bits/stdc++.h>
using namespace std;
const int mx = 1e6 + 10;
int n, a[mx], b[mx], c[mx];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (long long int i = 1; i < n + 1; i++) cin >> a[i];
  for (long long int i = 1; i < n + 1; i++) {
    b[i] = max(c[i - 1], b[i - 1]);
    c[i] = a[i] + b[i];
    cout << a[i] << ' ';
  }
  return 0;
}
