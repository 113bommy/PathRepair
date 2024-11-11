#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long n, m;
  cin >> n >> m;
  long long arr[n];
  for (long long i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  long long sum = 0;
  long long i = 0;
  while (arr[i] < 0 && i < m) {
    sum += arr[i++];
  }
  cout << abs(sum) << "\n";
}
