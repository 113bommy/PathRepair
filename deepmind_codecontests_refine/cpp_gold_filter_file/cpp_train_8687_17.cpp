#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0 && cin.tie(0) && cout.tie(0));
  ;
  int n, m, k, count = 0;
  cin >> n >> m >> k;
  int arr[m + 1];
  for (int i = 0; i <= m; i++) cin >> arr[i];
  for (int i = 0; i < m; i++) {
    if ((__builtin_popcount(arr[m] ^ arr[i])) <= k) count++;
  }
  cout << count << endl;
  return 0;
}
