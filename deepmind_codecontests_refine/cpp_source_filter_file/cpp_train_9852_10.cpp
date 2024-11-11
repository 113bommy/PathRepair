#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1234;
int n, m, c;
int p[MAXN];
int main() {
  cin >> n >> m >> c;
  for (int i = 0; i < n; ++i) p[i] = -1;
  int cnt = 0;
  for (int i = 0; i < m; ++i) {
    if (cnt == n) break;
    int x;
    cin >> x;
    if (x * 2 < c) {
      for (int j = 0; j < n; ++j)
        if (p[j] == -1 || x < p[j] || j == n - 1) {
          if (p[j] == -1) cnt++;
          p[j] = x;
          cout << j + 1 << endl;
          break;
        }
    } else {
      for (int j = n - 1; j >= 0; --j)
        if (p[j] == -1 || x > p[j] || j == 0) {
          if (p[j] == -1) cnt++;
          p[j] = x;
          cout << j + 1 << endl;
          break;
        }
    }
  }
  return 0;
}
