#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, l = 0, r = 0, p = 0;
  cin >> n;
  vector<long long> a(n), b, arr;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b.push_back(a[i]);
  }
  if (a[0] > a[n - 1]) {
    for (int i = 1; i < n; i++)
      if (a[i] >= a[i - 1])
        continue;
      else {
        l++;
        r = i;
      }
    if (l == 0)
      cout << 0 << "\n";
    else if (l == 1)
      cout << n - r << "\n";
    else
      cout << -1 << "\n";
  } else if (n == 2)
    cout << 0 << "\n";
  else
    cout << -1 << "\n";
  return 0;
}
