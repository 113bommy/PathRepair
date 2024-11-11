#include <bits/stdc++.h>
using namespace std;
long long a[110][110];
struct pace {
  long long ml, i, j, num, t;
};
pace st[10005];
int main() {
  long long n, m, q;
  cin >> n >> m >> q;
  long long cnt = q + 1;
  for (int i = 1; i <= q; i++) {
    int x;
    cin >> x;
    if (x == 3) {
      long long x1, y1, k;
      cin >> x1 >> y1 >> k;
      st[--cnt].ml = 3;
      st[cnt].i = x1;
      st[cnt].j = y1;
      st[cnt].num = k;
    } else if (x == 1) {
      long long tt;
      cin >> tt;
      st[--cnt].ml = 1;
      st[cnt].t = tt;
    } else if (x == 2) {
      long long tt;
      cin >> tt;
      st[--cnt].ml = 2;
      st[cnt].t = tt;
    }
  }
  for (int i = 1; i <= q; i++) {
    if (st[i].ml == 3) {
      a[st[i].i][st[i].j] = st[i].num;
    } else if (st[i].ml == 2) {
      int huan = a[n][st[i].t];
      for (int f = 2; f <= n; f++) {
        a[f][st[i].t] = a[f - 1][st[i].t];
      }
      a[1][st[i].t] = huan;
    } else if (st[i].ml == 1) {
      long long gg = a[st[i].t][m];
      for (int ff = m; ff >= 2; ff--) {
        a[st[i].t][ff] = a[st[i].t][ff - 1];
      }
      a[st[i].t][1] = gg;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
