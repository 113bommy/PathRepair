#include <bits/stdc++.h>
using namespace std;
int W, H, n;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> W >> H >> n;
  set<int> hol;
  set<pair<int, int> > hols;
  set<int> ver;
  set<pair<int, int> > vers;
  hol.insert(0);
  hol.insert(H);
  hols.insert(make_pair(H, 0));
  ver.insert(0);
  ver.insert(W);
  vers.insert(make_pair(W, 0));
  int ti = 0, tj = 0;
  while (n--) {
    char ast;
    int x;
    cin >> ast >> x;
    if (ast == 'H') {
      auto l = hol.lower_bound(x);
      l--;
      auto r = hol.upper_bound(x);
      auto tar = hols.find(make_pair(*r - *l, *l));
      hols.erase(tar);
      hols.insert(make_pair(*r - x, x));
      hols.insert(make_pair(x - *l, *l));
      hol.insert(x);
    } else {
      auto l = ver.lower_bound(x);
      l--;
      auto r = ver.upper_bound(x);
      auto tar = vers.find(make_pair(*r - *l, *l));
      vers.erase(tar);
      vers.insert(make_pair(*r - x, x));
      vers.insert(make_pair(x - *l, *l));
      ver.insert(x);
    }
    auto mx = hols.end();
    mx--;
    auto my = vers.end();
    my--;
    cout << mx->first * my->first << endl;
  }
}
