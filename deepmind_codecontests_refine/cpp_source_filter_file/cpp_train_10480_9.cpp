#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int a, b, c, n;
  cin >> a >> b >> c >> n;
  if (c < a + b && a + b - c < n) {
    cout << n - (a + b - c);
  } else {
    cout << -1;
  }
  return 0;
}
