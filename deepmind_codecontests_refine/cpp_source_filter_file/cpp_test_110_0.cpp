#include <bits/stdc++.h>
using namespace std;
const int max_n = 100000;
struct nd {
  int x, y, c;
} a[max_n];
int x[max_n], y[max_n], c[max_n], tmp[max_n], n, ans = 0;
priority_queue<int> q1;
priority_queue<int, vector<int>, greater<int> > q2;
void lsh(int *x) {
  for (int i = 0; i < n; i++) tmp[i] = x[i];
  sort(tmp, tmp + n);
  int nn = unique(tmp, tmp + n) - tmp;
  for (int i = 0; i < n; i++) {
    x[i] = lower_bound(tmp, tmp + nn, x[i]) - tmp;
  }
}
int solve(int *p, int ca) {
  while (!q1.empty()) q1.pop();
  while (!q2.empty()) q2.pop();
  for (int i = 0, j = 0; i < n; i = j) {
    while (j < n && a[j].x == a[i].x) {
      if (a[j].c == p[0]) {
        ca--;
        while (q1.size() > ca) q1.pop();
        while (q2.size() > ca) q2.pop();
      } else if (a[j].c == p[1]) {
        q1.push(a[j].y);
        while (q1.size() > ca) q1.pop();
      } else {
        q2.push(a[j].y);
        while (q2.size() > ca) q2.pop();
      }
      j++;
    }
    if (ca && q1.size() == ca && q2.size() == ca && q1.top() <= q2.top())
      return ca;
  }
  return 0;
}
inline void chmax(int &a, int b) {
  if (a < b) a = b;
}
void bigsolve(int *x, int *y, int ty = 1) {
  int p[3] = {0, 1, 2}, cc[3] = {0, 0, 0};
  for (int i = 0; i < n; i++)
    a[i].x = x[i], a[i].y = y[i], cc[a[i].c = c[i] - 1]++;
  sort(a, a + n, [](const nd &a, const nd &b) { return a.x < b.x; });
  do {
    chmax(ans, solve(p, cc[p[0]]));
  } while (next_permutation(p, p + 3));
  if (ty) {
    reverse(a, a + n);
    do {
      chmax(ans, solve(p, cc[p[0]]));
    } while (next_permutation(p, p + 3));
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> x[i] >> y[i] >> c[i];
  lsh(x), lsh(y);
  bigsolve(x, y), bigsolve(y, x);
  bigsolve(x, x, 0), bigsolve(y, y, 0);
  cout << ans * 3 << endl;
  return 0;
}
