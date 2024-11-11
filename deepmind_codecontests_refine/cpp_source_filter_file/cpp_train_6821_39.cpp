#include <bits/stdc++.h>
using namespace std;
struct node {
  int w, q;
};
node a[5001], b[5001];
int main() {
  int i, h, j, k, l, n, m, ans;
  cin >> n >> m >> k;
  for (i = 0; i < 5001; i++) {
    a[i].w = a[i].q = b[i].w = b[i].q = 0;
  }
  for (int p = 0; p < k; p++) {
    cin >> h >> j >> l;
    j--;
    if (h == 1) {
      a[j].w = l;
      a[j].q = p;
    } else {
      b[j].w = l;
      b[j].q = p;
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (a[i].q >= b[j].q) {
        cout << a[i].w << " ";
      } else
        cout << b[j].w << " ";
    }
    cout << endl;
  }
  return 0;
}
