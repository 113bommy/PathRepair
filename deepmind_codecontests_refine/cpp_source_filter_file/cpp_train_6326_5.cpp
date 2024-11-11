#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, i, p;
  cin >> n >> k;
  int a[n];
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < n; i++)
    if (a[i] > k) break;
  p = i;
  for (i = n - 1; i >= 0; i++)
    if (a[i] > k)
      break;
    else
      p++;
  if (p > n)
    cout << n;
  else
    cout << p;
}
