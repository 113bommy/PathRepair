#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int> > v;
vector<int> as, bs, c;
void colour(int x, int y) {
  if (!c[x]) {
    c[x] = y;
    if (y == 1) {
      as.push_back(x);
    } else {
      bs.push_back(y);
    }
  } else if (c[x] != y) {
    cout << -1 << endl;
    exit(0);
  } else {
    return;
  }
  for (vector<int>::iterator it = v[x].begin(); it != v[x].end(); it++) {
    if (y == 1) {
      colour(*it, 2);
    } else {
      colour(*it, 1);
    }
  }
}
int main() {
  cin >> n >> m;
  v.resize(n + 1);
  c.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  for (int i = 0; i < n; i++) {
    if (!c[i] && v[i].size()) {
      colour(i, 1);
    }
  }
  cout << as.size() << endl;
  for (vector<int>::iterator it = as.begin(); it != as.end(); it++) {
    if (it != as.begin()) {
      cout << " ";
    }
    cout << *it;
  }
  cout << endl;
  cout << bs.size() << endl;
  for (vector<int>::iterator it = bs.begin(); it != bs.end(); it++) {
    if (it != bs.begin()) {
      cout << " ";
    }
    cout << *it;
  }
  cout << endl;
  return 0;
}
