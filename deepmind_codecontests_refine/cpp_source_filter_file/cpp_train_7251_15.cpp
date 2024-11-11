#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s, i;
  cin >> n >> s;
  int h[10001], m[10001], flag2 = 0;
  for (i = 0; i < n; i++) cin >> h[i] >> m[i];
  if (h[0] == 0 && m[0] == 0) {
  } else {
    flag2 = 1;
    for (i = n - 1; i >= 0; i--) {
      h[i + 1] = h[i];
      m[i + 1] = m[i];
    }
    h[0] = m[0] = 0;
    n++;
  }
  int flag = 0;
  for (i = 0; i < n - 1; i++) {
    int ho = h[i];
    int mi = m[i];
    int cou = 0;
    while (ho != h[i + 1] || mi != m[i + 1]) {
      cou++;
      mi++;
      if (mi == 60) {
        mi = 0;
        ho++;
      }
    }
    if (i == 0 && cou - 1 > s && flag2 == 1) {
      cout << 0 << " " << 0 << endl;
      flag = 1;
      break;
    } else if (cou - 1 > 2 * s) {
      int hou = h[i];
      int minu = m[i];
      s++;
      while (s--) {
        minu++;
        if (minu == 60) {
          minu = 0;
          hou++;
        }
      }
      flag = 1;
      cout << hou << " " << minu << endl;
      break;
    }
  }
  if (!flag) {
    int hou = h[n - 1];
    int minu = m[n - 1];
    s++;
    while (s--) {
      minu++;
      if (minu == 60) {
        minu = 0;
        hou++;
      }
    }
    cout << hou << " " << minu << endl;
  }
}
