#include <bits/stdc++.h>
using namespace std;
const int N = 5555;
int n, k, m, a, g[N];
struct person {
  int cnt, time, id;
  bool operator<(person T) const {
    if (cnt != T.cnt) return cnt > T.cnt;
    return time < T.time;
  }
} t[N], now[N];
int query(int v) {
  int pos = 0;
  for (int i = 1; i <= n; ++i) {
    if (t[i].id == v) pos = i;
  }
  if (pos <= k && t[pos].cnt > 0) {
    int above = 0, rem = m - a;
    for (int i = pos + 1; i <= n; ++i) {
      int add = t[pos].cnt - t[i].cnt + 1;
      if (rem >= add) {
        rem -= add;
        above++;
      } else
        break;
    }
    if (pos + above <= k) return 1;
  }
  for (int i = 1; i <= n; ++i) {
    now[i] = t[i];
  }
  if (m - a > 0) {
    now[pos].cnt += m - a;
    now[pos].time = 1000000000;
  }
  sort(now + 1, now + 1 + n);
  for (int i = 1; i <= n; ++i) {
    if (now[i].id == v) pos = i;
  }
  if (pos <= k && now[pos].cnt > 0) {
    return 2;
  }
  return 3;
}
int main() {
  cin >> n >> k >> m >> a;
  for (int i = 1; i <= n; ++i) {
    t[i].id = i;
  }
  for (int i = 1; i <= a; ++i) {
    cin >> g[i];
    t[g[i]].cnt++;
    t[g[i]].time = i;
  }
  sort(t + 1, t + 1 + n);
  for (int i = 1; i <= n; ++i) {
    cout << query(i) << " ";
  }
  return 0;
}
