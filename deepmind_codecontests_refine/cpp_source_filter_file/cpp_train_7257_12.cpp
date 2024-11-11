#include <bits/stdc++.h>
using namespace std;
double pai = 3.141592653589793;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
struct nod {
  int x, y;
};
nod a[5], b[5];
int ms = -111111, mx = 100001, ml = 110000, mr = -100010;
int mms = -111110, mmx = 111110, mml = 111110, mmr = -111110;
int pd(nod temp) {
  int h = (mms - mmx) / 2;
  int x = temp.x - mml;
  int y = temp.y - mmx;
  if ((y >= (h - x)) && (y <= (h + x)) && (y <= (3 * h - x)) && (y >= (x - h)))
    return 1;
  return 0;
}
int pk(nod temp) {
  if ((temp.y > ms) || (temp.y < mx) || (temp.x > mr) || (temp.x < ml))
    return 0;
  return 1;
}
int main() {
  for (int i = 0; i < 4; i++) cin >> a[i].x >> a[i].y;
  for (int i = 0; i < 4; i++) {
    ms = max(ms, a[i].y);
    mx = min(mx, a[i].y);
    mr = max(mr, a[i].x);
    ml = min(ml, a[i].x);
  }
  a[4].x = (ml + mr) / 2;
  a[4].y = (ms + mx) / 2;
  for (int i = 0; i < 4; i++) cin >> b[i].x >> b[i].y;
  for (int i = 0; i < 4; i++) {
    mms = max(mms, b[i].y);
    mmx = min(mmx, b[i].y);
    mmr = max(mmr, b[i].x);
    mml = min(mml, b[i].x);
  }
  b[4].x = (mml + mmr) / 2;
  b[5].x = (mml + mmr) / 2;
  int ans = 0;
  for (int i = 0; i <= 4; i++) {
    ans += pd(a[i]);
  }
  for (int i = 0; i <= 4; i++) ans += pk(b[i]);
  if (ans > 0)
    cout << "YES";
  else
    cout << "NO";
}
