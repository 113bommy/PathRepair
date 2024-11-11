#include <bits/stdc++.h>
using namespace std;
long long a[110000];
int main() {
  long long n, x, s, i, max1 = -1, sum = 0;
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i], sum += a[i], max1 = max(max1, a[i]);
  s = sum / (n - 1);
  if (sum % (n - 1) != 0) s++;
  cout << min(s, max1) + 1;
}
