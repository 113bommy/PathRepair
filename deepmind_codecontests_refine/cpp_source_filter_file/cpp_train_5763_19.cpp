#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e15;
int n, m;
long long rig[2222], col[2222];
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i < 2 * n; i += 2)
    for (int j = 1; j < 2 * m; j += 2) {
      long long c;
      cin >> c;
      rig[i] += c;
      col[j] += c;
    }
  long long costor = INF;
  int ra = 0;
  for (int r = 0; r <= 2 * n; r += 2) {
    long long x = 0;
    for (int i = 1; i < 2 * n; i += 2) x += rig[i] * (r - i) * (r - i);
    if (x < costor) {
      costor = x;
      ra = r;
    }
  }
  long long costoc = INF;
  int ca = 0;
  for (int c = 0; c <= 2 * m; c += 2) {
    long long x = 0;
    for (int i = 1; i < 2 * m; i += 2) x += col[i] * (c - i) * (c - i);
    if (x < costoc) {
      costoc = x;
      ca = c;
    }
  }
  cout << (costor + costoc) * 4 << '\n' << ra / 2 << ' ' << ca / 2;
  return 0;
}
