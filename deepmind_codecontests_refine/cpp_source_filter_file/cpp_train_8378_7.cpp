#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<pair<long long, long long> > Lst;
  long long h, q;
  cin >> h >> q;
  long long x = (1LL << (h - 1));
  long long y = (1LL << h) - 1;
  int check = true;
  while (q--) {
    long long lvl, l, r, op;
    cin >> lvl >> l >> r >> op;
    long long d = h - lvl;
    for (long long i = 1; i <= d; i++) {
      l = l * 2;
      r = r * 2LL + 1LL;
    }
    if (op == 1) {
      if (y < l || r < x)
        check = false;
      else {
        x = max(x, l);
        y = min(y, r);
      }
    } else {
      Lst.push_back(make_pair(l, r));
    }
  }
  int p = -1;
  bool confused = false;
  sort(Lst.begin(), Lst.end());
  for (int i = 0; i < Lst.size(); i++) {
    if (x > Lst[i].second) {
    } else if (Lst[i].first <= x && y > Lst[i].second) {
      x = Lst[i].second + 1;
    } else if (Lst[i].first > x + 1 && y > x) {
      confused = true;
      break;
    } else if (Lst[i].first > x && y > x) {
      if (p != -1) {
        confused = true;
        break;
      }
      p = x;
      if (y <= Lst[i].second) {
        x = 1;
        y = -1;
        break;
      }
      x = Lst[i].second + 1;
    } else if (Lst[i].first <= x && Lst[i].second >= y) {
      if (p == -1) check = false;
      x = 1;
      y = -1;
      break;
    }
  }
  if ((p != -1 && x == y) || (x < y)) {
    confused = true;
  }
  if (!check)
    puts("Game cheated!");
  else if ((p != -1 || x == y) && !confused) {
    if (p != -1) x = p;
    printf("%lld\n", x);
  } else {
    puts("Data not sufficient!");
  }
  return 0;
}
