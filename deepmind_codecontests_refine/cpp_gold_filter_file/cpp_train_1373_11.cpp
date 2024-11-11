#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
struct node {
  int l, r;
} e[maxn], e1[maxn];
bool vis[maxn];
int main() {
  int x1, y1, x2, y2, x3, y3, x4, y4;
  cin >> x1 >> y1 >> x2 >> y2;
  cin >> x3 >> y3 >> x4 >> y4;
  if (x3 > x4) swap(x3, x4);
  if (y3 > y4) swap(y3, y4);
  for (int i = 0; i <= 1e6; i++) {
    if (i >= x3 && i < x4) {
      e[i].l = y3;
      e[i].r = y4;
    } else {
      e[i].l = 1e7 + 10;
      e[i].r = 0;
    }
  }
  for (int i = 0; i <= 1e6; i++) {
    if (i >= y3 && i < y4) {
      e1[i].l = x3;
      e1[i].r = x4;
    } else {
      e1[i].l = 1e7 + 10;
      e1[i].r = 0;
    }
  }
  cin >> x3 >> y3 >> x4 >> y4;
  if (x3 > x4) swap(x3, x4);
  if (y3 > y4) swap(y3, y4);
  for (int i = 0; i <= 1e6; i++) {
    if (i >= x3 && i < x4) {
      e[i].l = min(y3, e[i].l);
      e[i].r = max(y4, e[i].r);
    }
  }
  for (int i = 0; i <= 1e6; i++) {
    if (i >= y3 && i < y4) {
      e1[i].l = min(x3, e1[i].l);
      e1[i].r = max(x4, e1[i].r);
    }
  }
  if (x1 > x2) swap(x1, x2);
  if (y1 > y2) swap(y1, y2);
  int flag = 0;
  for (int i = 0; i <= 1e6; i++) {
    if (i >= x1 && i < x2) {
      if (e[i].l > y1 || e[i].r < y2) {
        flag = 1;
        break;
      }
    }
  }
  if (!flag)
    for (int i = 0; i <= 1e6; i++) {
      if (i >= y1 && i < y2) {
        if (e1[i].l > x1 || e1[i].r < x2) {
          flag = 1;
          break;
        }
      }
    }
  if (flag) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
