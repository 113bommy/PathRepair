#include <bits/stdc++.h>
using namespace std;
map<int, int> m;
int a[2000];
int main() {
  a[0] = 0;
  a[1] = 4;
  m[4] = 1;
  a[2] = 7;
  m[7] = 2;
  int pre = 2;
  int shi = 10;
  int id = 3;
  for (; a[id - 1] < 777777777;) {
    int tmp = id;
    for (int j = tmp - pre; j < tmp; j++) {
      a[id++] = 4 * shi + a[j];
      m[4 * shi + a[j]] = id - 1;
    }
    for (int j = tmp - pre; j < tmp; j++) {
      a[id++] = 7 * shi + a[j];
      m[7 * shi + a[j]] = id - 1;
    }
    pre *= 2;
    shi *= 10;
  }
  int n;
  while (cin >> n) {
    printf("%d\n", m[n]);
  }
  return 0;
}
