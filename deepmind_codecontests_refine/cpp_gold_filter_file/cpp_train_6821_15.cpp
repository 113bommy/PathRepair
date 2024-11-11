#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5 * 1000 + 10;
int r[MAXN], c[MAXN], tr[MAXN], tc[MAXN];
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < k; i++) {
    int t, a, b;
    cin >> t >> a >> b;
    if (t == 1) {
      r[a] = b;
      tr[a] = i + 1;
    } else {
      c[a] = b;
      tc[a] = i + 1;
    }
  }
  cerr << endl;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (tr[i] < tc[j])
        cout << c[j] << " ";
      else if (tr[i] > tc[j])
        cout << r[i] << " ";
      else
        cout << "0 ";
    }
    cout << endl;
  }
}
