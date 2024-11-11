#include <bits/stdc++.h>
using namespace std;
struct circle {
  int x, r, idx;
};
circle c[10000 + 32];
bool compare(circle p, circle q) { return (p.x) < (q.x); }
int n;
int getIdx(int x) {
  int low = 0, high = n - 1, mid;
  while (low <= high) {
    mid = (low + high) / 2;
    if (x >= (c[mid].x) - c[mid].r && x <= (c[mid].x) + c[mid].r) return mid;
    if (x < (c[mid].x) - c[mid].r) high = mid - 1;
    if (x > (c[mid].x) + c[mid].r) low = mid + 1;
  }
  return -1;
}
bool check(long long xc, long long r, long long xx, long long yy) {
  return (xx - xc) * (xx - xc) + yy * yy <= r * r;
}
int first[10000 + 32];
int main() {
  memset(first, -1, sizeof(first));
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> c[i].x >> c[i].r;
    c[i].idx = i + 1;
  }
  sort(c, c + n, compare);
  int m;
  cin >> m;
  long long res = 0;
  long long x, y, idx;
  int iidx;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    if (x < (c[0].x) - c[0].r || x > (c[n - 1].x) + c[n - 1].r) continue;
    idx = getIdx(x);
    if (idx == -1) continue;
    if (check(c[idx].x, c[idx].r, x, y)) {
      iidx = c[idx].idx;
      if (first[iidx] == -1) first[iidx] = i + 1;
    }
    if (idx != 0 && check(c[idx - 1].x, c[idx - 1].r, x, y)) {
      iidx = c[idx - 1].idx;
      if (first[iidx] == -1) first[iidx] = i + 1;
    }
    if (idx != n - 1 && check(c[idx + 1].x, c[idx + 1].r, x, y)) {
      iidx = c[idx + 1].idx;
      if (first[iidx] == -1) first[iidx] = i + 1;
    }
    {}
  }
  res = 0;
  for (int i = 1; i <= n; i++)
    if (first[i] != -1) res++;
  cout << res << endl;
  for (int i = 1; i <= n - 1; i++) cout << first[i] << " ";
  cout << first[n] << endl;
  return 0;
}
