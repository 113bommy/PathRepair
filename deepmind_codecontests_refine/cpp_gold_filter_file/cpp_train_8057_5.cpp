#include <bits/stdc++.h>
using namespace std;
long long hp[100005];
long long cur_hp[100005];
long long disk[100005];
long long cur_t[100005];
long long n, m;
bool calc(long long t) {
  long long a, b, c, d, e, cur, dp;
  cur = 0;
  for (a = 0; a < n; a++) {
    cur_hp[a] = hp[a];
    cur_t[a] = t;
  }
  for (a = 0; a < n; a++) {
    d = cur;
    e = 0;
    for (b = cur; b < m; b++) {
      c = (disk[b] - disk[cur]) +
          min(abs(hp[a] - disk[b]), abs(hp[a] - disk[cur]));
      if (c <= t)
        d = b;
      else
        break;
      e = 1;
    }
    if (e) cur = d + 1;
  }
  if (cur == m) return true;
  return false;
}
int main() {
  long long a, b, c, d, e, x, y, z, t;
  cin >> n >> m;
  for (a = 0; a < n; a++) cin >> hp[a];
  for (a = 0; a < m; a++) cin >> disk[a];
  long long lo, hi, mid;
  lo = 0;
  hi = 100000000000LL;
  while (1) {
    if (lo + 1 >= hi) break;
    mid = (lo + hi) / 2;
    if (!calc(mid))
      lo = mid + 1;
    else
      hi = mid;
  }
  if (calc(min(lo, hi)))
    cout << min(lo, hi) << endl;
  else
    cout << max(lo, hi) << endl;
  return 0;
}
