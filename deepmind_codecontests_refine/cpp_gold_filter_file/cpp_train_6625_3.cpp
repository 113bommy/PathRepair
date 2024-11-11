#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string x, y;
  cin >> x >> y;
  set<char> d;
  vector<char> c;
  map<char, int> ch;
  map<char, vector<int> > p;
  int in = -1, sum = 1, cont;
  bool o = 0;
  for (int i = 0; i < x.length(); i++) {
    if (!d.count(x[i])) {
      c.push_back(x[i]);
      p[x[i]].assign(x.length(), -1);
      ch[x[i]] = -1;
    }
    d.insert(x[i]);
  }
  for (int i = 0; i < y.length(); i++) {
    if (!d.count(y[i])) {
      cout << -1 << endl;
      return 0;
    }
  }
  for (int i = x.length() - 1; i >= 0; i--) {
    ch[x[i]] = i;
    for (int j = 0; j < c.size(); j++) {
      p[c[j]][i] = ch[c[j]];
    }
  }
  for (int i = 0; i < y.length(); i++) {
    in++;
    if (in == x.length()) {
      in = 0;
      sum++;
    }
    if (p[y[i]][in] == -1) {
      in = 0;
      sum++;
      in = p[y[i]][in];
    } else {
      in = p[y[i]][in];
    }
  }
  cout << sum << endl;
  return 0;
}
