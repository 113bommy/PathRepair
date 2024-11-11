#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long c, hr, hb, wr, wb, m, j, jo, mo, cou1, cou2, mx = 0;
  bool per, ch = 0;
  cin >> c >> hr >> hb >> wr >> wb;
  if (wb > c || wr > c) {
    if (wb > c && wr > c) {
      cout << 0 << endl;
      return 0;
    }
    if (wb > c) {
      j = (c / wr) * hr;
    } else {
      j = (c / wb) * hb;
    }
    cout << j << endl;
    return 0;
  }
  if (wr > 100) {
    for (int i = 1; (i * wr) <= c; i++) {
      m = i * wr;
      j = i * hr;
      j += ((c - m) / wb) * hb;
      if (j > mx) {
        mx = j;
      }
    }
    cout << mx << endl;
    return 0;
  }
  if (wb > 100) {
    for (int i = 1; (i * wr) <= c; i++) {
      m = i * wb;
      j = i * hb;
      j += ((c - m) / wr) * hr;
      if (j > mx) {
        mx = j;
      }
    }
    cout << mx << endl;
    return 0;
  }
  if (hb * wr <= wb * hr) {
    for (int i = 1; i < wr; i++) {
      m = i * wb;
      j = i * hb;
      j += ((c - m) / wr) * hr;
      if (j > mx) {
        mx = j;
      }
    }
    cout << mx << endl;
    return 0;
  } else {
    for (int i = 1; i < wb; i++) {
      m = i * wr;
      j = i * hr;
      j += ((c - m) / wb) * hb;
      if (j > mx) {
        mx = j;
      }
    }
    cout << mx << endl;
    return 0;
  }
  return 0;
}
