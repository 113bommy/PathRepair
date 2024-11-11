#include <bits/stdc++.h>
using namespace std;
int f[26], s[100][100];
int main() {
  int a, b, c, d, e, w, q, n;
  cin >> a >> b >> c >> d >> n;
  e = min(b, d);
  if (e % 2 == 0) {
    if (b > d) {
      w = 1;
      q = 0;
    } else {
      w = -1;
      q = a + c - 1;
    }
  } else {
    if (b > d) {
      w = -1;
      q = a + c - 1;
    } else {
      w = 1;
      q = 0;
    }
  }
  for (int i = 0; i < n; i++) cin >> f[i];
  int tmp = 0;
  for (int i = 0; i < e; i++) {
    while ((q >= 0) && (q <= a + c - 1)) {
      f[tmp]--;
      s[i][q] = tmp + 1;
      q += w;
      if (f[tmp] == 0) tmp++;
    }
    w = -w;
    if (q < 0)
      q = 0;
    else
      q = a + c - 1;
  }
  int e1 = max(b, d), l, r;
  if (b > d) {
    l = 0;
    r = a - 1;
  } else {
    l = a;
    r = a + c - 1;
  }
  for (int i = e; i < e1; i++) {
    while ((q >= l) && (q <= r)) {
      f[tmp]--;
      s[i][q] = tmp + 1;
      q += w;
      if (f[tmp] == 0) tmp++;
    }
    w = -w;
    if (q < l)
      q = l;
    else
      q = r;
  }
  cout << "YES" << endl;
  for (int i = 0; i < e1; i++) {
    for (int j = 0; j < a + c; j++) {
      if (s[i][j] == 0)
        cout << '.';
      else {
        char k = s[i][j] + 'a' - 1;
        cout << k;
      }
    }
    cout << endl;
  }
  return 0;
}
