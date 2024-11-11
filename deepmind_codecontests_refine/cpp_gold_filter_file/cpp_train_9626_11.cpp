#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 10;
int n, m, besta, bestb, mx, ca, cb, tp;
vector<pair<int, int> > d;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &tp);
    d.push_back(make_pair(tp, 1));
  }
  scanf("%d", &m);
  for (int j = 0; j < m; j++) {
    scanf("%d", &tp);
    d.push_back(make_pair(tp, 2));
  }
  sort(d.begin(), d.end());
  for (int j = n + m - 1; j >= 0; j--) {
    if (d[j].second == 2) {
      cb++;
    } else {
      ca++;
    }
    if (ca - cb >= mx) {
      mx = ca - cb;
      besta = ca;
      bestb = cb;
    }
  }
  printf("%d:%d", besta * 3 + (n - besta) * 2, bestb * 3 + (m - bestb) * 2);
  return 0;
}
