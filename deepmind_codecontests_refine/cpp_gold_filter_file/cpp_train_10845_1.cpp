#include <bits/stdc++.h>
using namespace std;
struct node {
  long long s, t;
};
node a[105], b[105];
bool cmp1(node x, node y) { return x.s < y.s; }
bool cmp2(node x, node y) { return x.s + x.t > y.s + y.t; }
long long n, r, x, y, i, cnt1, cnt2;
int main() {
  cin >> n >> r;
  for (i = 0; i < n; i++) {
    cin >> x >> y;
    if (y >= 0) {
      a[++cnt1].s = x;
      a[cnt1].t = y;
    } else {
      b[++cnt2].s = x;
      b[cnt2].t = y;
    }
  }
  sort(a + 1, a + cnt1 + 1, cmp1);
  sort(b + 1, b + cnt2 + 1, cmp2);
  for (i = 1; i <= cnt1; i++) {
    if (r < a[i].s) {
      cout << "NO" << endl;
      return 0;
    }
    r += a[i].t;
  }
  for (i = 1; i <= cnt2; i++) {
    if (r < b[i].s) {
      cout << "NO" << endl;
      return 0;
    }
    r += b[i].t;
  }
  if (r < 0)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
  return 0;
}
