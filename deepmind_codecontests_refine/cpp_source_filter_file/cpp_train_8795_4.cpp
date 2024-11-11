#include <bits/stdc++.h>
using namespace std;
int cnt[1001];
struct pt {
  int x, id;
};
bool comp(pt a, pt b) { return a.x < b.x; }
pt w[1001];
int main() {
  int n, mx = -1, ans = 1e9, res = 0, g;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> w[i].x;
    w[i].id = i;
  }
  sort(w + 1, w + n + 1, comp);
  g = w[1].x;
  while (1) {
    sort(w + 1, w + n + 1, comp);
    for (int i = 1; i <= n; i++) {
      if (w[i].id == 1) {
        g = i;
        break;
      }
    }
    bool may = false;
    for (int i = 1; i < n; i++) {
      if (w[n].x == w[i].x && g == i) {
        may = true;
        break;
      }
    }
    if (g == n && !may) break;
    if (w[n].x >= w[g].x) {
      w[g].x++;
      if (g != n)
        w[n].x--;
      else
        w[n - 1].x--;
      res++;
    }
  }
  cout << res;
}
