#include <bits/stdc++.h>
using namespace std;
long long n, a[600], mx;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  mx = a[2] | a[1];
  for (int k = 1; k <= n; k++)
    for (int i = 1 + k; i <= n; i++)
      for (int j = i + 1; j <= n; j++) mx = max(mx, a[i] | a[j] | a[k]);
  cout << mx << endl;
}
