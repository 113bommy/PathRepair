#include <bits/stdc++.h>
using namespace std;
int n, k, a[30], u[901], p, t;
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    cin >> a[i];
    u[a[i]] = true;
  }
  p = 1;
  for (int i = 0; i < k; i++) {
    cout << a[i] << " ";
    t = n - 1;
    while (t > 0) {
      while (u[p]) p++;
      cout << p << " ";
      t--;
    }
    cout << '\n';
  }
  return 0;
}
