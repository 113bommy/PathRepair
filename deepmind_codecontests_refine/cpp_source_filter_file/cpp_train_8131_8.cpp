#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, k, i, sum = 0, j = 0;
  cin >> n >> k;
  long long a[n];
  for (long long ppp = 0; ppp < n; ppp++) cin >> a[ppp];
  sort(a, a + n);
  for (i = 0, j = 0; i < k && j < n; j++)
    if (a[j] - sum <= 0)
      continue;
    else {
      cout << a[j] - sum << "\n";
      sum += a[j];
      i++;
    }
  if (i != k)
    for (; i < k; i++) cout << 0 << "\n";
  return 0;
}
