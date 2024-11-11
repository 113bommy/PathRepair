#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int INF = 0x3f3f3f3f;
long long a[MAXN];
struct node {
  long long x, y;
} b[MAXN];
int n;
int findpos(long long val) {
  int l = 1, r = n;
  int res = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (a[mid] < val) {
      l = mid + 1;
    } else {
      res = mid;
      r = mid - 1;
    }
  }
  return res;
}
void solve() {
  cin >> n;
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  sort(a + 1, a + 1 + n);
  int m;
  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> b[i].x >> b[i].y;
    int pos = findpos(b[i].x);
    if (pos == -1) {
      long long tmp = b[i].x - a[n];
      long long now = sum - a[n];
      if (now >= b[i].y)
        ;
      else {
        tmp += b[i].y - now;
      }
      cout << tmp << "\n";
    } else {
      long long minn = 1e18;
      long long now = sum - a[pos];
      if (now >= b[i].y)
        minn = 0;
      else {
        minn = b[i].y - now;
      }
      if (pos != 1) {
        pos--;
        long long now1 = b[i].x - a[pos];
        now = sum - a[pos];
        if (now < b[i].y) {
          now1 += b[i].y - now;
        }
        minn = min(minn, now1);
      }
      cout << minn << "\n";
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
