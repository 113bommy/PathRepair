#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, test, i, j, ara[200003 + 2], mark[200003 + 2];
  cin >> test;
  while (test--) {
    cin >> n;
    memset(mark, 0, sizeof(mark));
    for (int i = 1; i <= n; i++) cin >> ara[i];
    int mx = 0;
    for (int i = 1; i <= n; i++) {
      int x = ara[i];
      if (mark[x] == 0) {
        int cnt = 0;
        while (mark[x] == 0) {
          mark[x] = -1;
          x = ara[x];
          cnt++;
        }
        for (int i = 1; i <= n; i++) {
          if (mark[i] == -1) mark[i] = cnt;
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      if (i != 1) cout << " ";
      cout << mark[i];
    }
    cout << endl;
  }
  return 0;
}
