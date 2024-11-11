#include <bits/stdc++.h>
using namespace std;
int n, t;
int arr[2][4000][4000];
int ind0 = 0;
int ind1 = 1;
int a(int z, int x, int y) { return arr[z][x + 2000][y + 2000]; }
void add(int z, int x, int y, int cnt) { arr[z][x + 2000][y + 2000] += cnt; }
void clear(int z, int x, int y) { arr[z][x + 2000][y + 2000] = 0; }
void ost(int z, int x, int y) { arr[z][x + 2000][y + 2000] &= 3; }
void fun() {
  scanf("%d%d", &n, &t);
  add(0, 0, 0, n);
  int minim = 0;
  bool bo = true;
  while (bo) {
    bo = false;
    for (int i = -minim; i <= minim; ++i) {
      for (int j = -minim; j <= minim; ++j) {
        clear(ind1, i, j);
      }
    }
    for (int i = -minim; i <= minim; ++i) {
      for (int j = -minim; j <= minim; ++j) {
        if (a(ind0, i, j) >= 4) {
          bo = true;
          minim = max(minim, i + 1);
          int z = a(ind0, i, j) >> 2;
          add(ind1, i + 1, j, z);
          add(ind1, i - 1, j, z);
          add(ind1, i, j + 1, z);
          add(ind1, i, j - 1, z);
          ost(ind0, i, j);
        }
        add(ind1, i, j, a(ind0, i, j));
      }
    }
    if (ind0 == 0) {
      ind0 = 1;
      ind1 = 0;
    } else {
      ind0 = 0;
      ind1 = 1;
    }
  }
  for (; t; --t) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (abs(x) > 1000 || abs(y) > 1000)
      printf("0\n");
    else
      printf("%d\n", a(ind0, x, y));
  }
}
int main() {
  fun();
  return 0;
}
