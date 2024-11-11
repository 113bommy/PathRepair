#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long inf = 0x3f3f3f3f3f3f3f3f;
const long long mod = 1e9 + 7;
const int N = 1e6 + 10;
int n;
int qry(int x1, int y1, int x2, int y2) {
  int res;
  cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
  cin >> res;
  return res;
}
void ans(int x1, int y1, int x2, int y2) {
  cout << "! " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
  exit(0);
}
int sol(int r) {
  int L = 1, R = n;
  while (L < R) {
    int mid = (L + R) / 2;
    if (qry(r, 1, r, mid) & 1)
      R = mid;
    else
      L = mid + 1;
  }
  return L;
}
int sol2(int c) {
  int L = 1, R = n;
  while (L < R) {
    int mid = (L + R) / 2;
    if (qry(1, c, mid, c) & 1)
      R = mid;
    else
      L = mid + 1;
  }
  return L;
}
int main() {
  scanf("%d", &n);
  int q = 0;
  for (int i = 1; i <= n; i++) {
    if (qry(i, 1, i, n) & 1) {
      q = i;
      break;
    }
  }
  if (q != 0) {
    int x1 = q, y1 = sol(q);
    for (int i = n; i >= 1; i--) {
      if (qry(i, 1, i, n) & 1) {
        q = i;
        break;
      }
    }
    int x2 = q, y2 = sol(q);
    ans(x1, y1, x2, y2);
  } else {
    for (int i = 1; i <= n; i++) {
      if (qry(1, i, n, i) & 1) {
        q = i;
        break;
      }
    }
    int x1 = sol2(q), y1 = q;
    for (int i = n; i >= 1; i--) {
      if (qry(1, i, n, i) & 1) {
        q = i;
        break;
      }
    }
    int x2 = sol2(q), y2 = q;
    ans(x1, y1, x2, y2);
  }
  return 0;
}
