#include <bits/stdc++.h>
using namespace std;
string gen(int x, int y) {
  string ret = "";
  char p = x + 'A';
  for (int i = 0; i < y; ++i) {
    ret.push_back(p);
  }
  return ret;
}
int func(int x1, int y1, int x2, int y2, int x3, int y3, int o, int t, int th) {
  string a = gen(o, y1), b = gen(t, y2), c = gen(th, y3);
  if (x1 == x2 && x2 == x3 && x1 == (y1 + y2 + y3)) {
    cout << x1 << endl;
    for (int i = 0; i < x1; ++i) {
      cout << a + b + c << endl;
    }
    return x1;
  }
  if (x1 == x2 + x3 && x1 == (y1 + y2) && y3 == y2) {
    cout << x1 << endl;
    for (int i = 0; i < x1; ++i) {
      if (i < x2)
        cout << a + b << endl;
      else
        cout << a + c << endl;
    }
    return x1;
  }
  return -1;
}
int main(int argc, char const *argv[]) {
  int six[6];
  for (int i = 0; i < 6; ++i) {
    scanf("%d", &six[i]);
  }
  for (int i = 0; i < 8; ++i) {
    int tmp[6];
    for (int j = 0; j < 6; ++j) {
      tmp[j] = six[j];
    }
    if (i & 1) swap(tmp[5], tmp[4]);
    if (i & 2) swap(tmp[3], tmp[2]);
    if (i & 4) swap(tmp[0], tmp[1]);
    if (func(tmp[0], tmp[1], tmp[2], tmp[3], tmp[4], tmp[5], 0, 1, 2) != -1)
      return 0;
    if (func(tmp[2], tmp[3], tmp[0], tmp[1], tmp[4], tmp[5], 1, 0, 2) != -1)
      return 0;
    if (func(tmp[4], tmp[5], tmp[0], tmp[1], tmp[2], tmp[3], 2, 0, 1) != -1)
      return 0;
  }
  printf("%d\n", -1);
  return 0;
}
