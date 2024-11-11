#include <bits/stdc++.h>
using namespace std;
int b[1000], a[1000][1000], len[1000];
int n;
inline void make(int x, int s1, int s2) {
  if (s2 > s1) {
    int tem = 0;
    for (int i = len[x - 1]; i > 0; i--) tem += 9 - a[x - 1][i];
    if (tem < s2 - s1) {
      while (s2 > 0) {
        a[x][++len[x]] = min(9, s2);
        s2 -= 9;
      }
    } else {
      tem = s2 - s1;
      while (tem) {
        if (tem >= 9 - a[x - 1][len[x] + 1])
          a[x][++len[x]] = 9, tem -= 9 - a[x - 1][len[x]];
        else
          a[x][++len[x]] = a[x - 1][len[x]] + tem, tem = 0;
      }
      while (len[x] < len[x - 1]) a[x][++len[x]] = a[x - 1][len[x]];
    }
  } else {
    int tem = -1, i, j;
    for (i = 1; i <= len[x - 1]; i++) {
      tem += a[x - 1][i];
      if (tem >= s1 - s2) break;
    }
    tem = s2;
    len[x] = len[x - 1];
    for (j = i + 1; j <= len[x - 1]; j++) a[x][j] = a[x - 1][j];
    j = i + 1;
    a[x][j]++;
    while (a[x][j] > 9) {
      a[x][j] %= 10;
      a[x][++j]++;
    }
    if (j > len[x]) len[x]++;
    j = 1;
    for (int i = 1; i <= len[x]; i++) tem -= a[x][i];
    while (tem) {
      a[x][j++] = min(tem, 9);
      tem -= min(tem, 9);
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  len[0] = 1;
  for (int i = 1; i <= n; i++) cin >> b[i];
  for (int i = 1; i <= n; i++) {
    make(i, b[i - 1], b[i]);
    for (int j = len[i]; j > 0; j--) cout << a[i][j];
    cout << endl;
  }
}
