#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int oo = 1e9;
const int N = 1e6 + 10;
string s;
vector<pair<int, int> > vs;
vector<int> zr;
int main() {
  cin >> s;
  reverse(s.begin(), s.end());
  for (int i = 0; i < s.size(); ++i)
    if (s[i] == '1') vs.push_back(make_pair(i, i));
  vector<pair<int, int> > clr;
  for (int i = 0; i < vs.size(); ++i) {
    if (clr.size() && vs[i].first - clr.back().second == 1) {
      clr.back().second = vs[i].second;
      continue;
    }
    clr.push_back(vs[i]);
  }
  vs = clr;
  clr.clear();
  for (int i = 0; i < vs.size(); ++i) {
    if (clr.size() && vs[i].first - clr.back().second == 2) {
      if (vs[i].second - vs[i].first != 0 ||
          clr.back().second - clr.back().first != 0) {
        zr.push_back(vs[i].first - 1);
        clr.back().second = vs[i].second;
        continue;
      }
    }
    clr.push_back(vs[i]);
  }
  vector<int> a1, a2;
  for (int i = 0; i < clr.size(); ++i) {
    if (clr[i].first == clr[i].second) {
      a1.push_back(clr[i].first);
    } else {
      a2.push_back(clr[i].first);
      a1.push_back(+clr[i].second + 1);
    }
  }
  for (int i = 0; i < zr.size(); ++i) a2.push_back(zr[i]);
  printf("%d\n", (int)(a2.size() + a1.size()));
  for (int i = 0; i < a1.size(); ++i) {
    printf("+2^%d\n", a1[i]);
  }
  for (int i = 0; i < a2.size(); ++i) {
    printf("-2^%d\n", a2[i]);
  }
  return 0;
}
