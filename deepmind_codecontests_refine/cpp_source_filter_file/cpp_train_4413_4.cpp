#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, *a, s, t, d1 = 0, d2 = 0;
  cin >> n;
  a = new int[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  cin >> s >> t;
  if (s < t) {
    int tmp = t;
    t = s;
    s = tmp;
  }
  for (int i = t - 1; i < s - 1; i++) d1 += a[i];
  for (int i = s - 1; i < n; i++) d2 += a[i];
  for (int i = 0; i < t; i++) d2 += a[i];
  if (d1 > d2)
    cout << d2;
  else
    cout << d1;
  return 0;
}
