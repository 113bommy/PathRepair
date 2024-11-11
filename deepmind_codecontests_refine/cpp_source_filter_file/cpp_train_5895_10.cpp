#include <bits/stdc++.h>
using namespace std;
struct node {
  int t, l, r;
};
void solveFunction() {
  int n, q, m;
  cin >> n >> q >> m;
  vector<int> v(n + 1);
  for (int i = 1; i <= n; i++) cin >> v[i];
  vector<node> query(q);
  for (int i = 0; i < q; i++) {
    cin >> query[i].t >> query[i].l >> query[i].r;
  }
  while (m--) {
    int x;
    cin >> x;
    for (int i = q - 1; i >= 0; i--) {
      int l = query[i].l, r = query[i].r;
      if (query[i].t == 1) {
        if (l <= x && x <= r) {
          if (x == 1)
            x = n;
          else
            x = x - 1;
        }
      } else {
        if (l <= x && x <= r) {
          if ((r - l + 1) & 1) {
            int mid = (l + r) / 2;
            if (x <= mid) {
              x = mid + (mid - x);
            } else {
              x = mid - (x - mid);
            }
          } else {
            int mid = (l + r) / 2;
            if (x <= mid) {
              x = mid + 1 + (mid - x);
            } else {
              x = mid + 1 - (x - mid);
            }
          }
        }
      }
    }
    cout << v[x] << " ";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t = 1;
  while (t--) {
    solveFunction();
  }
}
