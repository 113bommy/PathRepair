#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long int n;
  cin >> n;
  int a[n], b[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] >= 0)
      b[i] = sqrt(a[i]);
    else
      b[i] = -sqrt(abs(a[i]));
  }
  long long int mx = -1;
  for (int i = 0; i < n; i++) {
    if (b[i] >= 0)
      if (b[i] * b[i] != a[i] && a[i] > mx) mx = a[i];
    if (b[i] < 0)
      if ((-b[i] * b[i]) != a[i] && a[i] > mx) mx = a[i];
  }
  cout << mx;
  return 0;
}
