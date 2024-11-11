#include <bits/stdc++.h>
using namespace std;
const int maxx = 110;
vector<pair<int, int> > v[maxx];
int b, d, la, lc, p = 0;
string a, c;
void get_ans(int ind, int p) {
  for (int i = ind; i < (la * b); i++) p += (c[p % lc] == a[i % la]);
  cout << (p / (lc * d)) << endl;
  exit(0);
}
int main() {
  cin >> b >> d;
  cin >> a >> c;
  la = a.length(), lc = c.length();
  for (int i = 0; i < (la * b); i++) {
    p += (c[p % lc] == a[i % la]);
    for (pair<int, int> x : v[i % la]) {
      if (x.first % lc == p % lc) {
        int r = i - x.second, e = p - x.first;
        int g = (la * b) - i - 1;
        g /= r;
        i += (g * r);
        p += (g * e);
        get_ans(i + 1, p);
      }
    }
    v[i % la].push_back(make_pair(p, i));
  }
  cout << (p / (lc * d)) << endl;
  return 0;
}
