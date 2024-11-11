#include <bits/stdc++.h>
using namespace std;
int n, x, y, m, k;
int a[30000008];
bool t[30000008];
struct arr {
  int x, y;
  arr() {}
  arr(int x1, int y1) {
    x = x1;
    y = y1;
  }
  bool operator<(const arr &t) const {
    return a[x] < a[t.x] || a[x] == a[t.x] && x != t.x;
  }
};
set<arr> q;
struct Tprogram {
  void open() {}
  void close() {}
  void init() {
    scanf("%d", &n);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      sum++;
      scanf("%d", &k);
      scanf("%d%d%d%d", a + sum, &x, &y, &m);
      q.insert(arr(sum, i));
      for (int j = 2; j <= k; j++)
        a[sum + 1] = ((long long)a[sum] * x + y) % m, sum++;
      t[sum] = 1;
    }
    int tmp = 0, ans = 0;
    for (int i = 1; i <= sum - 1; i++) {
      while (t[i]) i++, tmp = 0;
      if (a[i] > a[i + 1]) tmp++;
      ans = (ans > tmp ? ans : tmp);
    }
    printf("%d\n", ans);
    if (sum > 200000) return;
    int x = 0, y = 0;
    a[0] = -1;
    for (int i = 1; i <= sum; i++) {
      set<arr>::iterator p = q.lower_bound(arr(x, y));
      if (p == q.end()) p = q.begin();
      x = (*p).x, y = (*p).y;
      q.erase(p);
      printf("%d %d\n", a[x], y);
      if (!t[x]) q.insert(arr(x + 1, y));
    }
  }
  void work() {}
} Program;
int main() {
  Program.open();
  Program.init();
  Program.work();
  Program.close();
  return 0;
}
