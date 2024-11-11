#include <bits/stdc++.h>
using namespace std;
int n;
int k;
int f, s;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> k;
    if (k == 1) f = i;
    if (k == n) s = i;
  }
  if (f > s) swap(f, s);
  if (f - 1 < n - s)
    cout << n - f;
  else
    cout << n - 1;
  return 0;
}
