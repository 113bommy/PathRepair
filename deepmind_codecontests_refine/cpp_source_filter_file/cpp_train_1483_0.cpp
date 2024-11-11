#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> c(n + 1, 0), l(m + 1), p(m + 1);
  for (int i = 1; i <= m; i++) {
    cin >> l[i];
  }
  bool hai = 1;
  int cur = n, lb, prev_end = n;
  for (int i = m; i > 0; i--) {
    lb = cur - l[i] + 1;
    if (lb >= i)
      p[i] = lb;
    else {
      if (i + l[i] - 1 > prev_end) {
        hai = 0;
        break;
      } else
        p[i] = i;
    }
    cur = p[i] - 1;
    prev_end = p[i] + l[i] - 1;
  }
  if (p[1] != 1) hai = 0;
  if (hai)
    for (int i = 1; i <= m; i++) cout << p[i] << " ";
  else
    cout << "-1";
}
