#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, x, i, j, y;
  cin >> n >> x;
  long long a[n + 1], sum = 0;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  sum += n - 1;
  if (sum <= x)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
