#include <bits/stdc++.h>
using namespace std;
int main() {
  int q, c = 0;
  cin >> q;
  string old, now;
  map<string, string> root;
  vector<string> users;
  while (q--) {
    cin >> old;
    cin >> now;
    if (root.find(old) != root.end()) {
      root[root[old]] = now;
      root[now] = root[old];
    } else {
      root[old] = now;
      root[now] = old;
      users.push_back(old);
      c++;
    }
  }
  cout << c << endl;
  while (c--) cout << users[c] << " " << root[users[c]] << endl;
}
