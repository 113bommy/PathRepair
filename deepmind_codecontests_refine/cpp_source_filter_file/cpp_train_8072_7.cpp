#include <bits/stdc++.h>
using namespace std;
int n, t, i, j, a[100005], b[100005];
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i];
  for (i = 1; i <= n; i++) b[i] = b[i - 1] + a[i];
  for (i = n; i >= 1; i--)
    if (b[i + 1] + a[i] < b[i]) {
      j = i;
      b[i] = b[i + 1] + a[i];
    } else
      break;
  cout << j - 1 << " " << n - j + 1;
}
