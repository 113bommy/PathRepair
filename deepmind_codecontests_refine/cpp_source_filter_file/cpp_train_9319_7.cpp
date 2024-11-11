#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n + 1];
  int b[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int j = 1; j <= n; j++) {
    cin >> b[j];
  }
  sort(a + 1, a + n + 1);
  sort(b + 1, b + n + 1);
  int s1 = 0;
  int s2 = 0;
  int mx = 0;
  for (int i = n; i >= 1; i--) {
    s1 ^= a[i];
    s2 ^= b[i];
    mx = max(mx, s1 + s2);
  }
  cout << mx;
}
