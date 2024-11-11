#include <bits/stdc++.h>
using namespace std;
int n;
long long a[100005], b[100005];
bool check(int x, int y) { return a[x] > b[y]; }
int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long mn = a[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    b[i] = mn;
    mn = min(mn, a[i]);
  }
  for (int i = 0; i < n; i++) {
    long long r = n - 1, l = i, mid;
    while (l < r - 1) {
      mid = (l + r) / 2;
      if (check(i, mid))
        l = mid;
      else
        r = mid;
    }
    if (r >= n || b[l] > a[i])
      cout << -1 << ' ';
    else
      cout << r - i - 1 << ' ';
  }
  cout << endl;
  return 0;
}
