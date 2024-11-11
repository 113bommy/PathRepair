#include <bits/stdc++.h>
using namespace std;
const int mx = 1e5 + 10;
const double eps = 1e-9;
const long long inf = 1e18;
int a[mx], freq[130];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int m = *(max_element(a, a + n)), tmp = 0;
  for (int i = 0; i < n; i++) {
    if (m % a[i] == 0) {
      if (!freq[a[i]]) {
        freq[a[i]] = 1;
        a[i] = -1;
        tmp++;
      }
    }
  }
  sort(a, a + n);
  cout << m << " " << a[n - 1];
}
