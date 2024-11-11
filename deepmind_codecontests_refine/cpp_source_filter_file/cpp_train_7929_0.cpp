#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m, i;
  cin >> n;
  long long int arr1[n];
  for (i = 0; i < n; i++) cin >> arr1[i];
  cin >> m;
  long long int arr2[m];
  for (i = 0; i < m; i++) cin >> arr2[i];
  sort(arr1, arr1 + n);
  sort(arr2, arr2 + m);
  cout << arr1[n - 1] + arr2[m - 1];
}
