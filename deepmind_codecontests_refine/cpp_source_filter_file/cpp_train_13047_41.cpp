#include <bits/stdc++.h>
using namespace std;
struct Node {
  int v, m;
  int id;
  bool operator<(const Node &x) const {
    if (m != x.m) return m < x.m;
    return v < x.v;
  }
} q[100005];
int n, k, h;
bool ok(double times) {
  int i, j;
  for (j = 0, i = 1; i <= k; i++) {
    for (; j < n && q[j].v * times < (double)h * i + 1e-9; j++)
      ;
    if (j >= n) break;
    j++;
  }
  if (i > k) return true;
  return false;
}
int main() {
  cin >> n >> k >> h;
  for (int i = 0; i < n; i++) cin >> q[i].m;
  for (int i = 0; i < n; i++) {
    cin >> q[i].v;
    q[i].id = i + 1;
  }
  sort(q, q + n);
  double l = 0, r = 1e20, mid;
  for (int i = 0; i < 100; i++) {
    mid = (l + r) * 0.5;
    if (ok(mid))
      r = mid;
    else
      l = mid;
  }
  for (int j = 0, i = 1; i <= k; i++) {
    for (; j < n && q[j].v * r < (double)h * i + 1e-9; j++)
      ;
    cout << q[j].id << " ";
    j++;
  }
}
