#include <bits/stdc++.h>
using namespace std;
struct Planet {
  vector<int> a, b, c;
  void scan(int m) {
    string s;
    cin >> s;
    a.resize(m, 0);
    b.resize(m, 0);
    c.resize(m, 0);
    for (int i = 0; i < m; i++) {
      scanf("%d %d %d", &a[i], &b[i], &c[i]);
    }
  }
};
vector<Planet> a;
vector<pair<int, int> > b;
int main() {
  int n, m, K;
  scanf("%d %d %d", &n, &m, &K);
  a.resize(n);
  for (int i = 0; i < n; i++) {
    a[i].scan(m);
  }
  b.resize(m);
  int mx = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      for (int k = 0; k < m; k++) {
        b[k].first = a[j].b[k] - a[i].a[k];
        b[k].second = a[i].c[k];
      }
      sort(b.begin(), b.end());
      reverse(b.begin(), b.end());
      int cur = 0, cap = K;
      for (int i = 0; i < m && cap; i++) {
        if (b[i].first <= 0) break;
        int take = min(cap, b[i].second);
        cap -= take;
        cur += b[i].first * take;
      }
      if (cur > mx) {
        mx = cur;
      }
    }
  }
  printf("%d\n", mx);
  return 0;
}
