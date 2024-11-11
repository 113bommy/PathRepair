#include <bits/stdc++.h>
using namespace std;
const int N = 200100;
map<int, int> M;
int n, m, res1, res2, res, b[N], c[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    M[a]++;
  }
  cin >> m;
  res1 = 0;
  for (int i = 1; i <= m; i++) cin >> b[i];
  for (int i = 1; i <= m; i++) cin >> c[i];
  for (int i = 1; i <= m; i++) {
    int x, y;
    x = b[i];
    y = c[i];
    int t1 = M[x];
    int t2 = M[y];
    if (t1 > res1) {
      res1 = t1;
      res2 = t2;
      res = i;
    } else if (t1 == res1 && t2 > res2) {
      t2 = res2;
      res = i;
    }
  }
  cout << res << endl;
  return 0;
}
