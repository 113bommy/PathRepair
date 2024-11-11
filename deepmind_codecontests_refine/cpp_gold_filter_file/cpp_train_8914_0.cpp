#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> v(n);
  for (int& i : v) cin >> i;
  int a[n], ans[n];
  int temp = 1e9 + 98;
  for (int i = n - 1; i >= 0; i--) {
    ans[i] = -1;
    temp = min(temp, v[i]);
    a[i] = temp;
  }
  for (int i = 0; i < n; i++) {
    int lo = i + 1, hi = n - 1, res = -1, mid;
    while (lo <= hi) {
      mid = (lo + hi) / 2;
      if (a[mid] >= v[i])
        hi = mid - 1;
      else {
        res = mid;
        lo = mid + 1;
      }
    }
    if (res != -1) ans[i] = res - i - 1;
  }
  for (int i : ans) cout << i << ' ';
}
