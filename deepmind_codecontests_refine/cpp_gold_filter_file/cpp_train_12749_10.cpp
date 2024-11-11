#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n, l;
  cin >> n >> l;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  int rez = 2 * max(arr[0], l - arr[n - 1]);
  for (int i = 1; i <= n - 1; i++) rez = max(rez, (arr[i] - arr[i - 1]));
  cout << fixed << setprecision(15) << (float)rez / 2;
  return 0;
}
