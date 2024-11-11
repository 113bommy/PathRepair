#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 100;
const int A = 1e9;
int a[N][N];
int d[N];
bool b[N][N];
bool f(int x, int n, int m) {
  for (int i = 0; i < n; ++i) {
    fill(b[i], b[i] + m, false);
  }
  for (int i = 0; i < n; ++i) {
    int di = 0;
    for (int j = 0; j < m; ++j) {
      if (a[i][j] < x) continue;
      for (int k = 0; k < di; ++k) {
        if (b[d[k]][j]) {
          return true;
        }
        b[d[k]][j] = true;
      }
      d[di++] = j;
    }
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  int lo = 0, hi = A;
  while (lo < hi) {
    int mid = (lo + hi + 1) / 2;
    if (f(mid, n, m))
      lo = mid;
    else
      hi = mid - 1;
  }
  cout << lo << '\n';
}
