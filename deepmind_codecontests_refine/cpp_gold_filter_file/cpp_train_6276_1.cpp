#include <bits/stdc++.h>
using namespace std;
bool inside(int x, int y, int X, int Y, int R) {
  int dx = x - X;
  int dy = y - Y;
  return dx * dx + dy * dy <= R * R;
}
int main() {
  int XA, YA, XB, YB;
  cin >> XA >> YA >> XB >> YB;
  int N;
  cin >> N;
  int X[1005];
  int Y[1005];
  int R[1005];
  for (int i = 0; i < N; i++) cin >> X[i] >> Y[i] >> R[i];
  if (XA > XB) swap(XA, XB);
  if (YA > YB) swap(YA, YB);
  int res = 2 * (XB - XA + 1) + 2 * (YB - YA - 1);
  for (int x = XA; x <= XB; x++) {
    for (int i = 0; i < N; i++) {
      if (inside(x, YA, X[i], Y[i], R[i])) {
        res--;
        break;
      }
    }
    for (int i = 0; i < N; i++) {
      if (inside(x, YB, X[i], Y[i], R[i])) {
        res--;
        break;
      }
    }
  }
  for (int y = YA + 1; y < YB; y++) {
    for (int i = 0; i < N; i++) {
      if (inside(XA, y, X[i], Y[i], R[i])) {
        res--;
        break;
      }
    }
    for (int i = 0; i < N; i++) {
      if (inside(XB, y, X[i], Y[i], R[i])) {
        res--;
        break;
      }
    }
  }
  cout << res << endl;
  return 0;
}
