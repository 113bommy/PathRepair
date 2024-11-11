#include <bits/stdc++.h>
using namespace std;
long long L, R, v, d[5000005], val[5000005], ans;
void xe(long long a, long long l, long long r) {
  if (l >= L && r <= R) {
    ans = min(d[a], ans);
    return;
  }
  if (r < L || R < l) {
    return;
  }
  val[2 * a] += val[a];
  val[2 * a + 1] += val[a];
  long long mid = (l + r) / 2;
  d[2 * a] += val[a];
  d[2 * a + 1] += val[a];
  val[a] = 0;
  xe(2 * a, l, mid);
  xe(2 * a + 1, mid + 1, r);
}
void upd(long long a, long long l, long long r) {
  if (l >= L && r <= R) {
    val[a] += v;
    d[a] += v;
    return;
  }
  if (r < L || R < l) {
    return;
  }
  val[2 * a] += val[a];
  val[2 * a + 1] += val[a];
  long long mid = (l + r) / 2;
  d[2 * a] += val[a];
  d[2 * a + 1] += val[a];
  val[a] = 0;
  upd(2 * a, l, mid);
  upd(2 * a + 1, mid + 1, r);
  d[a] = min(d[2 * a], d[2 * a + 1]);
}
long long n, c, t, a, l, r;
char ch;
int main() {
  cin >> n;
  c = 1;
  while (c < n) {
    c *= 2;
  }
  for (int i = 0; i < n; i++) {
    cin >> d[i + c];
  }
  for (int i = c - 1; i >= 1; i--) {
    if (2 * i > c + n - 1) {
      continue;
    } else if (2 * i + 1 > c + n - 1) {
      d[i] = d[i * 2];
    } else
      d[i] = min(d[i * 2], d[i * 2 + 1]);
  }
  cin >> t;
  while (t--) {
    cin >> l >> r;
    l++;
    r++;
    L = l;
    R = r;
    ch = getchar();
    if (ch == ' ') {
      cin >> v;
      if (l > r) {
        L = l;
        R = n;
        upd(1, 1, c);
        L = 1;
        R = r;
        upd(1, 1, c);
      } else
        upd(1, 1, c);
    } else {
      ans = 1e18;
      if (l > r) {
        L = l;
        R = n;
        xe(1, 1, c);
        L = 1;
        R = r;
        xe(1, 1, c);
      } else
        xe(1, 1, c);
      cout << ans << endl;
    }
  }
}
