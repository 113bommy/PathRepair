#include <bits/stdc++.h>
using namespace std;
long long n, a[1005], b, c, d, i;
int main() {
  cin >> n;
  for (i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  if (n % 2 == 1)
    cout << a[n / 2];
  else
    cout << a[n / 2 - 1];
}
