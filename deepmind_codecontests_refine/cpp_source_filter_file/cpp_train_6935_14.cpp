#include <bits/stdc++.h>
using namespace std;
int h, m, s, st, en, nope[15];
inline int rem(int x) {
  if (x == 1)
    return 12;
  else
    return x - 1;
}
inline int add(int x) {
  if (x == 12)
    return 1;
  else
    return x + 1;
}
int main() {
  cin >> h >> m >> s >> st >> en;
  int ss = s / 5, mm = m / 5;
  if (ss == 0) ss = 12;
  if (mm == 0) mm = 12;
  if (s % 5 == 0) {
    nope[ss] = 1;
    nope[add(ss)] = 1;
  } else
    nope[add(ss)] = 1;
  if (m % 5 == 0 and s == 0) {
    nope[mm] = 1;
    nope[add(mm)] = 1;
  } else
    nope[add(mm)] = 1;
  if (s == 0 and m == 0) {
    nope[h] = 1;
    nope[add(h)] = 1;
  } else
    nope[add(h)] = 1;
  bool ye = 1;
  int cur = st;
  while (cur != en) {
    int nx = add(cur);
    if (nope[nx]) {
      ye = 0;
      break;
    }
    cur = nx;
  }
  if (ye) {
    cout << "YES\n";
    return 0;
  }
  ye = 0;
  cur = st;
  while (cur != en) {
    int nx = rem(cur);
    if (nope[cur]) {
      ye = 0;
      break;
    }
    cur = nx;
  }
  if (ye)
    cout << "YES\n";
  else
    cout << "NO\n";
}
