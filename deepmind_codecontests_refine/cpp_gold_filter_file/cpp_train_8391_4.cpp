#include <bits/stdc++.h>
using namespace std;
struct ptr {
  int x, ind;
} a[110];
bool cmp(ptr a, ptr b) { return a.x < b.x; }
set<int> s;
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) cin >> a[i].x >> a[i].ind;
  if (n == 1) return cout << 1, 0;
  sort(a, a + m, cmp);
  for (int i = 1; i < m; ++i)
    if (a[i - 1].x < n && a[i].x > n) {
      if (a[i - 1].ind == a[i].ind) return cout << a[i].ind, 0;
    }
  for (int i = 1; i <= 100; ++i) {
    bool flag = false;
    for (int j = 0; j < m; ++j) {
      if ((a[j].x - 1) / i + 1 != a[j].ind) flag = true;
    }
    if (!flag) s.insert((n - 1) / i + 1);
  }
  if (s.size() == 1)
    cout << *s.begin();
  else
    cout << -1;
  return 0;
}
