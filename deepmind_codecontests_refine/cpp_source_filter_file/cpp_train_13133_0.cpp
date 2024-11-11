#include <bits/stdc++.h>
using namespace std;
const int MaxN = 105;
string a[MaxN], start[MaxN], finish[MaxN], st[MaxN], Fans[MaxN];
int n, m, ind, Find;
int b[MaxN];
void check() {
  int flag = 0, flag1 = 0, i, j;
  ind = 0;
  for (i = 1; i <= n; i++) {
    if (b[i] == 1) {
      ind++;
      st[ind] = a[i];
    }
  }
  for (i = 1; i <= m; i++) {
    flag = 0;
    for (j = 1; j <= n; j++) {
      if ((st[j] == start[i]) || (st[j] == finish[i])) {
        flag++;
      }
    }
    if (flag == 2) {
      flag1 = 1;
      break;
    }
  }
  if ((flag1 == 0) && (ind > Find)) {
    for (i = 1; i <= ind; i++) {
      Fans[i] = st[i];
    }
    Find = ind;
  }
}
void rec(int i) {
  if (i > n) {
    check();
    return;
  }
  b[i] = 0;
  rec(i + 1);
  b[i] = 1;
  rec(i + 1);
}
int main() {
  int i, j;
  Find = 0;
  cin >> n >> m;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (i = 1; i <= m; i++) {
    cin >> start[i] >> finish[i];
  }
  rec(1);
  sort(Fans + 1, Fans + Find + 1);
  cout << Find << endl;
  for (i = 1; i <= Find; i++) {
    cout << Fans[i] << endl;
  }
}
