#include <bits/stdc++.h>
using namespace std;
int n, a[100005], b[100005], c[100005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  if (n % 2 == 0) {
    cout << -1;
    return 0;
  }
  for (int i = 0; i < n; i++) a[i] = i;
  for (int i = n - 1; i >= 0; i--) c[n - i - 1] = i;
  for (int i = 0; i < n; i++) {
    if (c[i] - a[i] >= 0)
      b[i] = c[i] - a[i];
    else
      b[i] = n + c[i] - a[i];
  }
  for (int i = 0; i < n; i++) cout << a[i] << " ";
  cout << "\n";
  for (int i = 0; i < n; i++) cout << b[i] << " ";
  cout << "\n";
  for (int i = 0; i < n; i++) cout << c[i] << " ";
  cout << "\n";
  return 0;
}
