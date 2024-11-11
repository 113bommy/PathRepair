#include <bits/stdc++.h>
using namespace std;
set<long long> s;
set<long long>::iterator it;
vector<long long> v;
int n;
int main() {
  int i, j, t;
  int s, x1, x2;
  scanf("%d %d %d", &s, &x1, &x2);
  int t1, t2;
  scanf("%d %d", &t1, &t2);
  int p, d;
  scanf("%d %d", &p, &d);
  int ptime = (x2 - x1) * t2;
  if (ptime < 0) ptime = -ptime;
  int tom = 0;
  int toi1 = 0;
  int toi2 = 0;
  int toi3 = 0;
  int ans = 0;
  if (x2 > p) {
    if (d == 1) {
      toi1 = (x2 - p) * t1;
      toi2 = toi1 + 2 * t1 * (s - x2);
    } else {
      toi1 = 2 * p * t1 + (x2 - p) * t1;
      toi2 = toi1 + 2 * t1 * (s - x2);
    }
  } else {
    if (d == 1) {
      toi1 = 2 * (s - p) * t1 + (p - x2) * t1;
      toi2 = toi1 + 2 * x2 * t1;
    } else {
      toi1 = (p - x2) * t1;
      toi2 = toi1 + 2 * x2 * t1;
    }
  }
  toi3 = toi1 + 2 * s * t1;
  if (x2 > x1) {
    if (p <= x1) {
      if (toi1 < ptime)
        ans = toi1;
      else
        ans = ptime;
    }
    if (p > x1 && p < x2) {
      if (d == 1) {
        if (toi3 < ptime)
          ans = toi3;
        else
          ans = ptime;
      } else {
        if (toi1 < ptime)
          ans = toi1;
        else
          ans = ptime;
      }
    }
    if (p > x2) {
      if (toi2 < ptime)
        ans = toi2;
      else
        ans = ptime;
    }
  } else {
    if (p >= x1) {
      if (toi1 < ptime)
        ans = toi1;
      else
        ans = ptime;
    }
    if (p < x1 && p > x2) {
      if (d == -1) {
        if (toi3 < ptime)
          ans = toi3;
        else
          ans = ptime;
      } else {
        if (toi1 < ptime)
          ans = toi1;
        else
          ans = ptime;
      }
    }
    if (p <= x2) {
      if (toi2 < ptime)
        ans = toi2;
      else
        ans = ptime;
    }
  }
  printf("%d\n", ans);
  return 0;
}
