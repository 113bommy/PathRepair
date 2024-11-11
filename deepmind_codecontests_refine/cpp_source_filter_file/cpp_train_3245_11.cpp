#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, k;
  cin >> n >> k;
  long long int arr[n], drnk[k];
  for (long long int i = 0; i < k; i++) {
    drnk[i] = 0;
  }
  for (long long int i = 0; i < n; i++) {
    cin >> arr[i];
    drnk[arr[i]]++;
  }
  long long int cnt = 0;
  for (long long int i = 0; i < k; i++) {
    if (drnk[i] % 2 != 0) {
      cnt++;
    }
  }
  cnt = cnt / 2;
  cout << n - cnt;
  return 0;
}
