#include <bits/stdc++.h>
using namespace std;
int n;
set<pair<pair<int, int>, int> > posSet;
set<pair<int, pair<int, int> > > lenSet;
int a[210005];
template <typename T>
T nextt(T x) {
  x++;
  return x;
}
inline int rev(const int& x) { return 210005 - x; }
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  int start = 0;
  for (int i = 0; i < (n); i++) {
    cin >> a[i];
    if (i != 0 && a[i] != a[i - 1]) {
      int len = i - start;
      lenSet.insert(pair<int, pair<int, int> >(
          len, pair<int, int>(rev(start), rev(i - 1))));
      posSet.insert(
          pair<pair<int, int>, int>(pair<int, int>(start, i - 1), len));
      start = i;
    }
  }
  {
    int len = n - start;
    lenSet.insert(pair<int, pair<int, int> >(
        len, pair<int, int>(rev(start), rev(n - 1))));
    posSet.insert(pair<pair<int, int>, int>(pair<int, int>(start, n - 1), len));
  }
  int c = 0;
  while (lenSet.size() > 1) {
    auto it = lenSet.end();
    it--;
    pair<int, pair<int, int> > p = *it;
    int ln, st, en;
    ln = p.first;
    st = rev(p.second.first);
    en = rev(p.second.second);
    lenSet.erase(p);
    c++;
    auto x = posSet.lower_bound(
        pair<pair<int, int>, int>(pair<int, int>(st, en), ln));
    bool noJoin = false;
    if (x == posSet.begin()) {
      noJoin = true;
    }
    if (x == posSet.end()) {
      cout << st << " " << en << " " << ln << endl;
      cout << "fuck you\n";
      return 0;
    }
    if (nextt(x) == posSet.end()) {
      noJoin = true;
    }
    if (noJoin) {
      posSet.erase(*x);
      continue;
    }
    pair<pair<int, int>, int> lps, rps;
    x--;
    lps = *x;
    x++;
    x++;
    rps = *x;
    x--;
    posSet.erase(*x);
    if (a[lps.first.first] != a[rps.first.first]) {
      continue;
    }
    int lln, lst, len, rln, rst, ren;
    lln = lps.second;
    lst = lps.first.first;
    len = lps.first.second;
    rln = rps.second;
    rst = rps.first.first;
    ren = rps.first.second;
    pair<int, pair<int, int> > llp = *lenSet.lower_bound(
        pair<int, pair<int, int> >(lln, pair<int, int>(rev(lst), rev(len))));
    pair<int, pair<int, int> > rlp = *lenSet.lower_bound(
        pair<int, pair<int, int> >(rln, pair<int, int>(rev(rst), rev(ren))));
    posSet.erase(lps);
    posSet.erase(rps);
    lenSet.erase(llp);
    lenSet.erase(rlp);
    pair<pair<int, int>, int> pl(pair<int, int>(lst, ren), lln + rln);
    pair<int, pair<int, int> > lp(lln + rln,
                                  pair<int, int>(rev(lst), rev(ren)));
    posSet.insert(pl);
    lenSet.insert(lp);
  }
  c++;
  cout << c << endl;
}
