#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int n, a, b;
  cin >> n >> a >> b;
  long long int arr[n];
  for (long long int i = 0; i < n; i++) cin >> arr[i];
  if (n == 2) return cout << abs(arr[0] - arr[1]), 0;
  sort(arr, arr + n);
  long long int t = arr[b];
  long long int k = arr[b - 1];
  cout << t - k;
}
