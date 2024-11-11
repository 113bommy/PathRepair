#include <bits/stdc++.h>
using namespace std;
int n, q;
int a[1000000], p[1000000], tr[1000000], b[1000000];
void upd(int pos, int del) {
  for (; pos < n; pos |= (pos + 1)) tr[pos] += del;
}
int sum(int r) {
  int s = 0;
  for (; r >= 0; r = (r & (r + 1)) - 1) s += tr[r];
  return s;
}
void UPD(int x) {
  if (x > 0 && p[x - 1] > p[x] && b[x - 1] == 0) {
    b[x - 1] = 1;
    upd(x - 1, 1);
  } else if (x > 0 && p[x - 1] < p[x] && b[x - 1] == 1) {
    b[x - 1] = 0;
    upd(x - 1, -1);
  }
  if (x < n - 1 && p[x] > p[x + 1] && b[x] == 0) {
    b[x] = 1;
    upd(x, 1);
  } else if (x < n - 1 && p[x] < p[x + 1] && b[x] == 1) {
    b[x] = 0;
    upd(x, -1);
  }
}
int main() {
  cin >> n;
  int x;
  for (int(i) = (0); i < (n); ++(i)) {
    scanf("%d", &x);
    --x;
    a[i] = x;
    p[x] = i;
  }
  for (int(i) = (0); i < (n - 1); ++(i))
    if (p[i] > p[i + 1]) {
      b[i] = 1;
      upd(i, 1);
    }
  cin >> q;
  for (int(i) = (0); i < (q); ++(i)) {
    int t, x, y;
    scanf("%d%d%d", &t, &x, &y);
    --x;
    --y;
    if (t == 1) {
      cout << sum(y) - sum(x - 1) + 1 << '\n';
    } else {
      swap(a[x], a[y]);
      p[a[x]] = x;
      p[a[y]] = y;
      UPD(a[x]);
      UPD(a[y]);
    }
  }
  return 0;
}
