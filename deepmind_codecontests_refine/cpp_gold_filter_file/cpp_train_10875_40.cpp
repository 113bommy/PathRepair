#include <bits/stdc++.h>
using namespace std;
const int Maxn = 53, Inf = 10000;
int n, m, a, b, tr[Maxn][Maxn];
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> tr[i][j];
    }
  }
  cin >> a >> b;
  int minn = Inf;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (n - i >= a && m - j >= b) {
        int t = 0;
        for (int k = i; k < i + a; k++) {
          for (int l = j; l < j + b; l++) {
            if (tr[k][l] == 1) t++;
          }
        }
        minn = min(minn, t);
      }
      if (n - i >= b && m - j >= a) {
        int t = 0;
        for (int k = i; k < i + b; k++) {
          for (int l = j; l < j + a; l++) {
            if (tr[k][l] == 1) t++;
          }
        }
        minn = min(minn, t);
      }
    }
  }
  cout << minn;
}
