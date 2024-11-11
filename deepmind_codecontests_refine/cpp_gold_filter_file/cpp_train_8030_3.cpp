#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  long long int a[n - 1];
  for (int i = 0; i < n - 1; i++) cin >> a[i];
  long long int s[n], m = INT_MAX;
  s[0] = 0;
  for (int i = 1; i < n; i++) {
    s[i] = s[i - 1] + a[i - 1];
    m = min(m, s[i]);
  }
  m = min(s[0], m);
  long long int x = 1 - m;
  long long int p[n], l[n];
  for (int i = 0; i < n; i++) {
    p[i] = x + s[i];
    l[i] = p[i];
  }
  for (int i = 0; i < n; i++) {
    if (p[i] > n || p[i] < 1) {
      cout << "-1" << endl;
      return 0;
    }
  }
  sort(l, l + n);
  long long int z = unique(l, l + n) - l;
  if (z != n) {
    cout << "-1" << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) cout << p[i] << " ";
  return 0;
}
