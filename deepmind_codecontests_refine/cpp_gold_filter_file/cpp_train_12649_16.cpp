#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
long long n;
int arr[200005];
long long ini = 0, fin = 0;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  int ans = INT_MAX;
  for (int i = 0; i * 2 < n; i++) ans = min(ans, arr[n / 2 + i] - arr[i]);
  cout << ans << "\n";
  return 0;
}
