#include <bits/stdc++.h>
const int N = 3e5 + 5, MAX = 3e7, MOD = 5000000;
using namespace std;
int n, a[N], b[N], gg, mx;
bool wa3;
bool check(int x) {
  set<int> s;
  for (int i = 0; i < n; i++) s.insert(a[i]);
  int curr = 0;
  std::vector<int> c;
  for (int i = 0; i < n; i++) c.push_back(b[i]);
  while (x--) {
    auto it = s.upper_bound(c[curr]);
    if (it != s.begin()) {
      if (c[curr]) it--;
      c.push_back(*it);
      s.erase(it);
      s.insert(c[curr++]);
    } else {
      c.push_back(*it);
      s.erase(it);
      s.insert(c[curr++]);
    }
  }
  for (int i = curr; i < ((int)(c).size()) - 1; i++) {
    if (!c[i] || c[i] > c[i + 1]) return false;
  }
  return true;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) {
    if (b[i] == 1) wa3 = true;
  }
  if (wa3) {
    for (int i = 1; i <= n; i++) {
      if (a[i] != 0 && a[i] - 1 < i) mx = max(mx, i - a[i] + 1);
    }
    printf("%d\n", n + mx);
    return 0;
  }
  bool wa1 = true;
  bool wa2 = false;
  for (int i = 1; i <= n; i++) {
    if (wa2 && (a[i] != a[i - 1] + 1)) wa1 = false;
    if (a[i] == 1) wa2 = true;
  }
  if (wa1) {
    bool ans = true;
    for (int i = 1; i <= n; i++) {
      if (a[i] == 1) gg = i;
    }
    for (int i = 1; i <= n; i++) {
      if (a[i] == 1) break;
      if (a[i] == 0) continue;
      if (a[i] - a[n] <= i) ans = false;
    }
    if (ans)
      printf("%d\n", gg - 1);
    else {
      printf("%d\n", gg + n);
    }
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] == 1) gg = i;
  }
  wa2 = false;
  for (int i = 1; i <= n; i++) {
    if (wa2 && a[i] != 0) mx = max(mx, i - gg - a[i] + 1);
    if (a[i] == 1) wa2 = true;
  }
  printf("%d\n", n + mx + gg);
}
