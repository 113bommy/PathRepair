#include <bits/stdc++.h>
using namespace std;
long long a[1010][1010], b[1010];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long i, j, cnt = 3, k, pre = 1, cur, tp, l = 1;
  cin >> k;
  if (k == 1) {
    cout << "2\nNY\nYN\n";
    return 0;
  }
  tp = k;
  while (tp > 1) {
    b[l++] = tp % 2;
    tp /= 2;
  }
  l--;
  for (i = 1; i <= l; i++) {
    tp = pre;
    if (b[i] == 1) {
      for (j = i; j < l; j++) {
        cur = cnt + 1;
        a[pre][cnt] = 1;
        a[cnt][pre] = 1;
        a[cnt][cur] = 1;
        a[cur][cnt++] = 1;
        pre = cnt++;
      }
      a[pre][cnt] = 1;
      a[cnt][pre] = 1;
      a[cnt][2] = 1;
      a[2][cnt++] = 1;
    }
    pre = tp;
    if (i != l)
      cur = cnt + 2;
    else
      cur = 2;
    a[pre][cnt] = 1;
    a[cnt][pre] = 1;
    a[cur][cnt] = 1;
    a[cnt++][cur] = 1;
    a[pre][cnt] = 1;
    a[cnt][pre] = 1;
    a[cur][cnt] = 1;
    a[cnt++][cur] = 1;
    pre = cnt++;
  }
  cnt--;
  cnt--;
  cout << cnt << "\n";
  for (i = 1; i <= cnt; i++) {
    for (j = 1; j <= cnt; j++)
      if (a[i][j] == 1)
        cout << "Y";
      else
        cout << "N";
    cout << "\n";
  }
  return 0;
}
