#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n, m, c;
  cin >> n >> m >> c;
  vector<int> a(n), b(m);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int j = 0; j < m; j++) cin >> b[j];
  vector<int> beg(n);
  beg.assign(n, 0);
  vector<int> start(n), end(n);
  start.assign(n, 0);
  end.assign(n, 0);
  int max;
  if (n >= 2 * m) {
    for (int i = 0; i < m; ++i) {
      beg[i] = i + 1;
      start[i] = 0;
      end[i] = start[i] + beg[i];
    }
    for (int i = m; i < n - m + 1; ++i) {
      beg[i] = m;
      start[i] = 0;
      end[i] = start[i] + beg[i];
    }
    for (int i = n - m + 1; i < n; ++i) {
      beg[i] = n - i;
      start[i] = start[i - 1] + 1;
      end[i] = start[i] + beg[i];
    }
  } else {
    for (int i = 0; i < n - m + 1; ++i) {
      beg[i] = i + 1;
      start[i] = 0;
      end[i] = start[i] + beg[i];
    }
    for (int i = n - m + 1; i < m; ++i) {
      beg[i] = n - m + 1;
      start[i] = start[i - 1] + 1;
      end[i] = start[i] + beg[i];
    }
    for (int i = m; i < n; ++i) {
      beg[i] = n - i;
      start[i] = start[i - 1] + 1;
      end[i] = start[i] + beg[i];
    }
  }
  vector<int> sum(m);
  sum.assign(m, 0);
  sum[0] = b[0] % c;
  for (int i = 1; i < m; ++i) sum[i] = (sum[i - 1] + b[i]) % c;
  a[0] = (a[0] + b[0]) % c;
  cout << a[0] << " ";
  for (int i = 1; i < n; ++i) {
    a[i] = (a[i] + sum[end[i] - 1] - sum[start[i]] + b[start[i]]) % c;
    cout << a[i] << " ";
  }
  return 0;
}
