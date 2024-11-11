#include <bits/stdc++.h>
using namespace std;
const int mxn = 1e5 + 5;
const int inf = 1e9;
bool query(int r1, int c1, int r2, int c2) {
  cout << "? " << r1 << " " << c1 << " " << r2 << " " << c2 << endl;
  string s;
  cin >> s;
  return s[0] == 'Y';
}
int main() {
  int n;
  cin >> n;
  int s = 2;
  vector<pair<int, int> > v;
  v.push_back({1, 1});
  int r = 1;
  int c = 1;
  while (2 * n - s - 1 >= n - 1) {
    if (r < n && query(r + 1, c, n, n))
      r++;
    else
      c++;
    s++;
    v.push_back({r, c});
  }
  int pt = v.size() - 2;
  vector<pair<int, int> > rv;
  rv.push_back({n, n});
  int p = n;
  int q = n;
  while (p + q - r - c > 1) {
    if (query(v[pt].first, v[pt].second, p, q - 1))
      q--;
    else
      p--;
    rv.push_back({p, q});
    pt--;
  }
  reverse(rv.begin(), rv.end());
  for (int i = 0; i < rv.size(); i++) v.push_back(rv[i]);
  string res = "";
  for (int i = 1; i < v.size(); i++) {
    if (v[i].first == v[i - 1].first)
      res += "R";
    else
      res += "D";
  }
  cout << "? " << res << endl;
}
