#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n + 3];
  a[0] = 0;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) a[i] += a[i - 1];
  int mx = 0;
  for (int i = 1; i <= n; i++)
    for (int j = i; j <= n; j++) {
      mx = max(mx, a[i] + a[n] - a[j - 1] + ((j - i + 1) - (a[j] - a[i - 1])));
    }
  cout << mx << endl;
}
