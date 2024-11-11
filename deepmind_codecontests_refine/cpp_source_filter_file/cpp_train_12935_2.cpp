#include <bits/stdc++.h>
using namespace std;
const int maxx = 2e5;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int a[n];
  int bits[20];
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    for (int j = 0; j < 20; ++j) {
      if (a[i] & (i << j)) bits[j]++;
    }
  }
  long long int ans = 0;
  for (int i = 0; i < n; ++i) {
    long long int x = 0;
    for (int j = 0; j < 20; ++j) {
      if (bits[j] != 0) {
        x = x | (1 << j);
        bits[j]--;
      }
    }
    ans += x * x;
  }
  cout << ans;
  return 0;
}
