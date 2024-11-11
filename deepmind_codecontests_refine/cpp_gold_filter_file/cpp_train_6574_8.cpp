#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const double eps = 1e-6;
const int mod = 1000000007;
int modpow(int x, int y, int md = mod) {
  if (y == 0) return 1;
  int ret = modpow(x, y >> 1, md);
  ret = (long long)ret * ret % md;
  if (y & 1) ret = (long long)ret * x % md;
  return ret;
}
int n;
void query(int x1, int y1, int x2, int y2) {
  printf("? %d %d %d %d\n", x1, y1, x2, y2);
  fflush(stdout);
}
void submit(int x1, int y1, int x2, int y2) {
  printf("! %d %d %d %d\n", x1, y1, x2, y2);
  fflush(stdout);
  exit(0);
}
int main() {
  cin >> n;
  vector<int> row, col;
  for (int i = 1; i <= n; i++) {
    query(i, 1, i, n);
    int t;
    cin >> t;
    if (t & 1) row.push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    query(1, i, n, i);
    int t;
    cin >> t;
    if (t & 1) col.push_back(i);
  }
  if (row.size() && col.size()) {
    query(row[0], col[0], row[0], col[0]);
    int t;
    cin >> t;
    if (t & 1) {
      submit(row[0], col[0], row[1], col[1]);
    } else {
      submit(row[0], col[1], row[1], col[0]);
    }
  } else if (row.size()) {
    int l = 0, r = n;
    while (r - l > 1) {
      int mid = l + r >> 1;
      query(row[0], 1, row[0], mid);
      int t;
      cin >> t;
      if (t & 1)
        r = mid;
      else
        l = mid;
    }
    submit(row[0], r, row[1], r);
  } else {
    int l = 0, r = n;
    while (r - l > 1) {
      int mid = l + r >> 1;
      query(1, col[0], mid, col[0]);
      int t;
      cin >> t;
      if (t & 1)
        r = mid;
      else
        l = mid;
    }
    submit(r, col[0], r, col[1]);
  }
  return 0;
}
