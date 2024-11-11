#include <bits/stdc++.h>
using namespace std;
int n, a[2001], b[1001], k, t, o;
int main() {
  cin >> n >> t;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n);
  o = n;
  for (int i = 1; i <= n; i++) {
    if (a[i] + t > 5) o = i - 1, i = n + 1;
  }
  cout << o / 3;
}
