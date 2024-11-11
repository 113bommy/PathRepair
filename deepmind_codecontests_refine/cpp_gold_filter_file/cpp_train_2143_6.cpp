#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n, temp, i, j, k;
  int a[10017];
  for (i = 0; i < 10017; i++) a[i] = 0;
  cin >> n >> k;
  long long ans = 0;
  for (i = 0; i < n; i++) {
    cin >> temp;
    a[temp]++;
  }
  for (i = 0; i < 10017; i++) {
    for (j = i; j < 10017; j++) {
      if (__builtin_popcount(i ^ j) == k) {
        ans += (i != j ? (long long)a[i] * a[j]
                       : ((long long)a[i] * (a[i] - 1)) / 2);
      }
    }
  }
  cout << ans;
  return 0;
}
