#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1005;
int a[MaxN][MaxN], str[MaxN], stl[MaxN];
int main() {
  ios_base::sync_with_stdio(0);
  int i, j, n, m, k, i1, x, y, cc;
  char c;
  for (i = 0; i < MaxN; i++) {
    str[i] = i;
    stl[i] = i;
  }
  cin >> n >> m >> k;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  for (i1 = 0; i1 < k; i1++) {
    cin >> c >> x >> y;
    x--;
    y--;
    if (c == 'g') {
      cout << a[str[x]][stl[y]] << endl;
    }
    if (c == 'c') {
      swap(stl[x], stl[y]);
    }
    if (c == 'r') {
      swap(str[x], str[y]);
    }
  }
  cin.get();
  cin.get();
}
