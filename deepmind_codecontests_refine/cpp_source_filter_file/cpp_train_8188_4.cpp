#include <bits/stdc++.h>
#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
char _;
using namespace std;
int n;
int a[110];
long long ans;
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n * 2; i++) cin >> a[i];
  for (int i = 0; i < n * 2; i += 2) {
    for (int j = i + 1; j < n * 2; j++) {
      if (a[i] == a[j]) {
        for (int k = j; k > i + 1; k--) {
          swap(a[k - 1], a[k]);
          ans++;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
