#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 100;
int n, m, w, a[maxn], c[2 * maxn];
bool check(int h) {
  memset(c, 0, sizeof(c));
  int add = 0, used = 0;
  for (int i = 0; i < n; i++) {
    add += c[i];
    int now = max(0, h - (a[i] + add));
    used += now;
    add += now;
    c[i + w] -= now;
    if (used > m) return false;
  }
  return true;
}
int main() {
  cin >> n >> m >> w;
  for (int i = 0; i < n; i++) cin >> a[i];
  int lb = 1, rb = 1e9 + 1e5;
  while (rb - lb > 1) {
    int mid = (rb + lb) / 2;
    if (check(mid))
      lb = mid;
    else
      rb = mid;
  }
  cout << lb;
  return 0;
}
