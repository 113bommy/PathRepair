#include <bits/stdc++.h>
using namespace std;
int main() {
  int arr[110];
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> arr[i];
  sort(arr, arr + n);
  reverse(arr, arr + n);
  --n;
  for (int i = 1; i <= n / 2; i += 2) swap(arr[i], arr[n - 1]);
  for (int i = 0; i < n + 1; ++i) cout << arr[i] << " ";
  cout << endl;
  return 0;
}
