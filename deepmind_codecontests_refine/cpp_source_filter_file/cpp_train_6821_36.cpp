#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int r[5005], c[5005];
int col[100005];
int main() {
  memset(r, 0, sizeof(r));
  memset(c, 0, sizeof(c));
  cin >> n >> m >> k;
  int op, pos;
  for (int i = 1; i <= k; i++) {
    cin >> op >> pos >> col[i];
    if (op == 1) {
      r[pos] = i;
    } else {
      c[pos] = i;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << col[max(r[i], c[j])] << ' ';
    }
    cout << endl;
  }
}
