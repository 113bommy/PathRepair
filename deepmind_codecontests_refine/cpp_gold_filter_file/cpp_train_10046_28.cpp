#include <bits/stdc++.h>
using namespace std;
template <class T1>
void deb(T1 e1) {
  cerr << "--> " << e1 << endl;
}
template <class T1, class T2>
void deb(T1 e1, T2 e2) {
  cerr << "--> " << e1 << " " << e2 << endl;
}
template <class T1, class T2, class T3>
void deb(T1 e1, T2 e2, T3 e3) {
  cerr << "--> " << e1 << " " << e2 << " " << e3 << endl;
}
template <class T1, class T2, class T3, class T4>
void deb(T1 e1, T2 e2, T3 e3, T4 e4) {
  cerr << "--> " << e1 << " " << e2 << " " << e3 << " " << e4 << endl;
}
template <class T1, class T2, class T3, class T4, class T5>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5) {
  cerr << "--> " << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5
       << endl;
}
template <class T1, class T2, class T3, class T4, class T5, class T6>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5, T6 e6) {
  cerr << "--> " << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5
       << " " << e6 << endl;
}
int main() {
  int n, x1, x2, y1, y2;
  scanf("%d", &n);
  scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
  int dis = 99999999;
  if ((x1 == 0 && x2 == 0) or (x1 == n && x2 == n))
    dis = abs(y1 - y2);
  else if ((y1 == 0 && y2 == 0) or (y1 == n && y2 == n))
    dis = abs(x1 - x2);
  else {
    dis = min(dis, x1 + x2 + y1 + y2);
    dis = min(dis, abs(x1 - 0) + abs(y1 - n) + abs(x2 - 0) + abs(y2 - n));
    dis = min(dis, abs(x1 - n) + abs(y1 - 0) + abs(x2 - n) + abs(y2 - 0));
    dis = min(dis, abs(x1 - n) + abs(y1 - n) + abs(x2 - n) + abs(y2 - n));
  }
  printf("%d\n", dis);
  return 0;
}
