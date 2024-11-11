#include <bits/stdc++.h>
using namespace std;
const int M = 100000 + 5;
long long int mod = 1000000000 + 7;
long long int a[M];
long long int b[M];
int main() {
  time_t t_start, t_end;
  t_start = clock();
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  long long int r = 10000000000 + 100;
  long long int l = 0;
  while (l < r) {
    long long int mid = (l + r) / 2;
    bool ok = true;
    int pa = 0;
    int pb = 0;
    while (pa < n && pb < m) {
      long long int y = mid;
      if (b[pb] < a[pa]) {
        long long int x = a[pa] - b[pb];
        if (x > mid) {
          ok = false;
          break;
        }
        if (mid >= 3 * x) {
          y = mid - 2 * x;
        } else {
          y = (mid - x) / 2;
        }
      }
      while (pb < m && b[pb] - a[pa] <= y) {
        pb++;
      }
      pa++;
    }
    if (pb < m) {
      ok = false;
    }
    if (ok) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << r << endl;
  t_end = clock();
  return 0;
}
