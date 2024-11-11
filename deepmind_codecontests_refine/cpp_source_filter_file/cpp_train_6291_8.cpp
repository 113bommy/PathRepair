#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, ary[102], ch[102][102], i, j, res[102];
  while (scanf("%d", &n) == 1) {
    for (i = 0; i < n; i++) {
      scanf("%d", &ary[i]);
    }
    memset(ch, 0, sizeof(ch));
    for (i = 0; i < n; i++) {
      for (j = 0; j < ary[i]; j++) {
        cin >> ch[i][j];
      }
    }
    int k = 0;
    for (i = 0; i < n; i++) {
      int s = 0;
      for (j = 0; j < n; j++) {
        if (ch[i][j] > 0) {
          s += ((ch[i][j]) * 5);
        }
      }
      s += (ary[i] * 15);
      res[k++] = s;
    }
    sort(res, res + k);
    cout << res[0] << endl;
  }
  return 0;
}
