#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int N = 500100;
int n, k, m, x, res;
int p[N];
struct point {
  int val;
  int ind;
} a[N];
bool sc(const point &a, const point &b) {
  return a.val < b.val || a.val == b.val && a.ind < b.ind;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    a[i].val = x;
    a[i].ind = i;
  }
  sort(a + 1, a + 1 + n, sc);
  int i = 1;
  int j = 1;
  int rigth = 0;
  while (i <= n) {
    if (a[i].val != a[i - 1].val)
      j = i + 1;
    else
      j = rigth;
    while (a[i].val == a[j].val && j <= n) {
      if (a[j].ind - a[i].ind + 1 <= k + (j - i + 1))
        res = max(res, j - i + 1);
      else {
        rigth = j;
        break;
      }
      j++;
    }
    i++;
  }
  cout << max(res, 1);
  return 0;
}
