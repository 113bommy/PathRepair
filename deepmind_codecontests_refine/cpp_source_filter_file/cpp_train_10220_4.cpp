#include <bits/stdc++.h>
using namespace std;
long long arr[1001];
int main() {
  int n, t, k;
  long long c2 = 0, c = 0;
  cin >> t;
  for (int i = 0; i < t; i++) {
    c2 = 0;
    cin >> n >> k;
    memset(arr, 0, n);
    for (int j = 0; j < n; j++) {
      cin >> arr[j];
    }
    sort(arr, arr + n);
    int c = arr[0] + k;
    for (int j = 0; j < n; j++) {
      if (abs(c - arr[i]) <= k) c2++;
    }
    if (c2 == n)
      cout << c << "\n";
    else
      cout << -1 << "\n";
  }
}
