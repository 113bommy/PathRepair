#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, m;
long long a[N], b[N];
int ok(long long T) {
  int first = 1;
  for (int i = 1; i <= n && first <= m; i++) {
    long long where = a[i];
    if (abs(where - b[first]) > T) continue;
    if (b[first] < where) {
      long long last = first + 1;
      while (min(2 * (where - b[first]) + b[last] - where,
                 where - b[first] + 2 * (b[last] - where)) <= T)
        last++;
      last--;
      first = last;
    } else {
      while ((b[first] - where) <= T) first++;
      first--;
    }
    first++;
  }
  return first > m;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= m; ++i) cin >> b[i];
  long long left = 0, right = 1e15, rs = -1;
  while (left <= right) {
    long long mid = (left + right) / 2;
    if (ok(mid))
      rs = mid, right = mid - 1;
    else
      left = mid + 1;
  }
  cout << rs;
  return 0;
}
