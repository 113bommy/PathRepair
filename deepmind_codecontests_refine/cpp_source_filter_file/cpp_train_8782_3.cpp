#include <bits/stdc++.h>
using namespace std;
const int INF = ~(1 << 31);
const double EPS = 1;
const double PI = 3.141592653589793;
int main() {
  int n, m, mq = 1000000, q;
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> q;
    mq = min(q, mq);
  }
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort((a).rbegin(), (a).rend());
  int r = 0, i = 0;
  while (i < n) {
    int j = 0;
    while (i < n && j < q) {
      r += a[i];
      i++;
      j++;
    }
    j = 0;
    while (i < n && j < 2) {
      i++;
      j++;
    }
  }
  cout << r << endl;
  return 0;
}
