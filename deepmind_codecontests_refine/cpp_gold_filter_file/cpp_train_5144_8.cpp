#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  int n, m;
  cin >> n >> m;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  int sum = 0;
  sort(arr, arr + n);
  for (int i = 0; i < n; i++) {
    if (arr[i] < 0 && m > 0)
      sum += arr[i], m--;
    else
      break;
  }
  cout << abs(sum) << "\n";
  return 0;
};
