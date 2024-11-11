#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000];
int solve() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  int m = INT_MIN;
  for (int i = 0; i < n; i++) {
    int c = 1;
    int l = i;
    int r = i;
    while (l > 0 && a[l - 1] <= a[l]) {
      c++;
      l--;
    }
    while (r < n - 1 && a[r + 1] <= a[r]) {
      c++;
      r++;
      ;
    }
    if (c > m) m = c;
  }
  return m;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << solve() << endl;
}
