#include <bits/stdc++.h>
using namespace std;
int arr[102];
void prog() {
  string s;
  int i, j, k, l, m = 0, n, o = 0, p;
  cin >> n;
  k = 0;
  for (i = 0; i < n; i++) {
    cin >> arr[i];
    k += arr[i];
  }
  sort(arr, arr + n);
  cout << arr[n - 1] * n - k;
}
int main() {
  int t = 1;
  while (t--) prog();
  return 0;
}
