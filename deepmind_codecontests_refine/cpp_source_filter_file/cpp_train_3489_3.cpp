#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> x, y, t;
long long calc(int a, int b, int c) {
  long long x1 = x[a];
  long long y1 = y[a];
  long long x2 = x[b];
  long long y2 = y[b];
  long long xx = x[c];
  long long yy = y[c];
  return (yy - y1) * (y1 - y2) - (xx - x1) * (x1 - x2);
}
bool inside(int p) {
  if ((calc(t[0], t[1], p) <= 0 && calc(t[0], t[1], t[2]) > 0) ||
      (calc(t[0], t[1], p) >= 0 && calc(t[0], t[1], t[2]) < 0))
    return false;
  if ((calc(t[0], t[2], p) <= 0 && calc(t[0], t[2], t[1]) > 0) ||
      (calc(t[0], t[2], p) >= 0 && calc(t[0], t[2], t[1]) < 0))
    return false;
  if ((calc(t[2], t[1], p) <= 0 && calc(t[2], t[1], t[0]) > 0) ||
      (calc(t[2], t[1], p) >= 0 && calc(t[2], t[1], t[0]) < 0))
    return false;
  return true;
}
bool inseg(int p, int a, int b) {
  if (calc(a, b, p) != 0) return false;
  if (((long long)(x[p] - x[a])) * (x[p] - x[b]) > 0) return false;
  if (((long long)(y[p] - y[a])) * (y[p] - y[b]) > 0) return false;
  return true;
}
bool tri() {
  if (calc(t[0], t[1], t[2]) != 0) return true;
  return false;
}
int main() {
  cin >> n;
  x.resize(n);
  y.resize(n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &x[i], &y[i]);
  }
  t.resize(3);
  t[0] = 0;
  t[1] = 1;
  for (int i = 2; i < n; i++) {
    t[2] = i;
    if (tri()) break;
  }
  for (int i = 2; i < n; i++) {
    if (i == t[2]) continue;
    bool tmp = inside(i);
    if (tmp) {
      t[2] = i;
    } else if (inseg(i, t[1], t[2])) {
      t[2] = i;
    } else if (inseg(i, t[1], t[0])) {
      t[1] = i;
    } else if (inseg(i, t[2], t[0])) {
      t[2] = i;
    }
  }
  for (int i = 0; i < 3; i++) cout << t[i] + 1 << " ";
}
