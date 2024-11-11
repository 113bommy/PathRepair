#include <bits/stdc++.h>
using namespace std;
int aVal(int x) {
  if (x > 0) return x;
  if (x < 0) return -x;
  if (x == 0) return 0;
}
int main() {
  int Xq, Yq, Xf, Yf;
  cin >> Xq >> Yq >> Xf >> Yf;
  if (aVal(Xq - Xf) <= 1 && aVal(Yq - Yf) <= 1) {
    cout << 8 << endl;
    return 0;
  }
  if (Xq >= Xf && Yq >= Yf) {
    int Px = Xq - (Xf - 1), Py = Yq - (Yf + 1), Rx = Xq - (Xf + 1),
        Ry = Yf - (Yf - 1);
    int path = aVal(Px) + aVal(Py) + aVal(Rx) + aVal(Ry) + 4;
    cout << path << endl;
    return 0;
  }
  if (Xq >= Xf && Yq <= Yf) {
    int Px = Xq - (Xf - 1), Py = Yq - (Yf - 1), Rx = Xq - (Xf + 1),
        Ry = Yf - (Yf + 1);
    int path = aVal(Px) + aVal(Py) + aVal(Rx) + aVal(Ry) + 4;
    cout << path << endl;
    return 0;
  }
  if (Xq <= Xf && Yq <= Yf) {
    int Px = Xq - (Xf + 1), Py = Yq - (Yf - 1), Rx = Xq - (Xf - 1),
        Ry = Yf - (Yf + 1);
    int path = aVal(Px) + aVal(Py) + aVal(Rx) + aVal(Ry) + 4;
    cout << path << endl;
    return 0;
  }
  if (Xq <= Xf && Yq >= Yf) {
    int Px = Xq - (Xf + 1), Py = Yq - (Yf + 1), Rx = Xq - (Xf - 1),
        Ry = Yq - (Yf - 1);
    int path = aVal(Px) + aVal(Py) + aVal(Rx) + aVal(Ry) + 4;
    cout << path << endl;
    return 0;
  }
}
