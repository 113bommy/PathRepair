#include <bits/stdc++.h>
using namespace std;
vector<int> b;
vector<pair<int, int> > r;
void move(int what, int from, int to, bool ok) {
  if (what == b.size()) return;
  if (b[what] == 1) ok = true;
  int other = 1 + 2 + 3 - from - to;
  if (ok) {
    move(what + 1, from, other, true);
    for (int _n(b[what]), i(0); i < _n; i++)
      r.push_back(pair<int, int>(from, to));
    move(what + 1, other, to, true);
  } else {
    if (what == b.size() - 1) {
      for (int _n(b[what] - 1), i(0); i < _n; i++)
        r.push_back(pair<int, int>(from, other));
      r.push_back(pair<int, int>(from, to));
      for (int _n(b[what] - 1), i(0); i < _n; i++)
        r.push_back(pair<int, int>(other, to));
      return;
    }
    move(what + 1, from, to, true);
    for (int _n(b[what]), i(0); i < _n; i++)
      r.push_back(pair<int, int>(from, other));
    move(what + 1, to, from, true);
    for (int _n(b[what]), i(0); i < _n; i++)
      r.push_back(pair<int, int>(other, to));
    move(what + 1, to, from, ok);
  }
}
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int _n(n), i(0); i < _n; i++) cin >> a[i];
  for (int _n(n), i(0); i < _n; i++) {
    int c = 1;
    while (i < n - 1 && a[i] == a[i + 1]) {
      i++;
      c++;
    }
    b.push_back(c);
  }
  move(0, 1, 3, false);
  printf("%d\n", r.size());
  for (int _n(r.size()), i(0); i < _n; i++) {
    printf("%d %d\n", r[i].first, r[i].second);
  }
  return 0;
}
