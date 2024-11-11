#include <bits/stdc++.h>
using namespace std;
int a[100];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  int i = 0, j = n - 1;
  for (i; i < n and a[i] <= k; i++)
    ;
  for (j; j >= 0 and a[j] <= k; j--)
    ;
  if (i > j)
    cout << n << endl;
  else
    cout << n - (j - i + 1) << endl;
  return 0;
}
