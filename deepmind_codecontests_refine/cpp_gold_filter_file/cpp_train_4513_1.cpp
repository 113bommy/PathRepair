#include <bits/stdc++.h>
using namespace std;
int a[1000001], b[1000001], n, k, i;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> k, b[k] = i;
  for (i = 1; i < n; i++)
    if (b[a[i]] > b[a[i + 1]]) break;
  cout << n - i << endl;
  return 0;
}
