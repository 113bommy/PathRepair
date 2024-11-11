#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
int main() {
  int n, m, s, f;
  cin >> n >> m >> s >> f;
  long t[100000];
  int l[100000], r[100000];
  for (int i = 0; i < m; i++) {
    cin >> t[i] >> l[i] >> r[i];
  }
  t[m] = 1000000001;
  int pos = 1;
  int tps = s;
  int tm = 0;
  while (tps != f) {
    for (int i = pos; i < t[tm]; i++) {
      if (tps == f) return 0;
      if (f > s) {
        cout << "R";
        tps++;
      } else {
        cout << "L";
        tps--;
      }
    }
    if (tps == f) return 0;
    int np = (f - s) / abs(f - s);
    if (((tps >= l[tm]) && (tps <= r[tm])) ||
        ((tps + np >= l[tm]) && (tps + np <= r[tm])))
      cout << "X";
    else {
      if (f > s) {
        cout << "R";
        tps++;
      } else {
        cout << "L";
        tps--;
      }
    }
    pos = t[tm] + 1;
    tm++;
  }
  return 0;
}
