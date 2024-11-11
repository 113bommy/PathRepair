#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
string a, b;
long long int n, k;
vector<long long int> v;
bool chk(long long int time) {
  long long int done = 0, f = 0;
  for (long long int i = 1; i < n + 1; i++) {
    if (a[i] == 'P') {
      f = 0;
      long long int left = i;
      for (long long int j = done + 1; j < i; j++)
        if (a[j] == '*') {
          left = j;
          break;
        }
      if (i - left > time) return false;
      long long int leftfirst_r = time - (i) + 2 * left;
      long long int rightfirst_r = (time + (i) + left) / 2;
      done = max(leftfirst_r, rightfirst_r);
    }
  }
  for (long long int i = done + 1; i < n + 1; i++) {
    if (a[i] == '*') return false;
  }
  return true;
}
void solve() {
  cin >> n;
  cin >> b;
  a += '0';
  a += b;
  for (long long int i = 1; i < n + 1; i++) {
    if (a[i] == '*') v.push_back(i);
  }
  long long int h = n, l = 0, mid, ans = -1;
  while (l <= h) {
    mid = (l + h) / 2;
    if (chk(mid)) {
      ans = mid;
      h = mid - 1;
    } else
      l = mid + 1;
  }
  cout << ans << endl;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long int t = 1, u = 0;
  while (t--) {
    solve();
  }
}
