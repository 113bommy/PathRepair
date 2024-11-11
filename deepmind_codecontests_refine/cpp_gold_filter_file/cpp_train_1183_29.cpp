#include <bits/stdc++.h>
using namespace std;
long long n, k, a[50], i;
int main() {
  cin >> n >> k;
  for (i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  if (n >= k)
    cout << a[n - k] << " " << a[n - k];
  else
    cout << "-1";
  return 0;
}
