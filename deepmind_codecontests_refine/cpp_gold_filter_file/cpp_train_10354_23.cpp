#include <bits/stdc++.h>
using namespace std;
int n, a[100010], mx, an;
int main() {
  cin >> n;
  cin >> a[1];
  mx = a[1];
  for (int i = 2; i <= n; ++i) {
    cin >> a[i];
    if (((a[i - 1] - a[i])) < 0) {
      mx = max(mx, a[i]);
    } else {
      an += (a[i - 1] + a[i]);
    }
  }
  cout << mx;
}
