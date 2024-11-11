#include <bits/stdc++.h>
using namespace std;
int k, n, i;
long long int a[51];
int main() {
  cin >> n >> k;
  for (i = 1; i <= n; i++) cin >> a[i];
  if (n < k)
    cout << "-1";
  else {
    sort(a, a + n + 1);
    cout << a[k - 1] << " 0";
  }
}
