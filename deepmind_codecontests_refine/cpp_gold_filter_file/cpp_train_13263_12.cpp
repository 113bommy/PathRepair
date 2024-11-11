#include <bits/stdc++.h>
using namespace std;
void solve() {
  int x;
  set<int> s;
  map<int, int> mp;
  char ch;
  vector<int> v;
  vector<int> M[1000];
  while (scanf("%d%c", &x, &ch)) {
    v.push_back(x);
    if (ch == '\n') break;
  }
  sort(v.begin(), v.end());
  M[0].push_back(v[0]);
  int p = 0;
  for (int i = 1; i < v.size(); i++) {
    if (v[i] - v[i - 1] == 1) {
      M[p].push_back(v[i]);
    } else if (v[i] > v[i - 1]) {
      p++;
      M[p].push_back(v[i]);
    }
  }
  for (int i = 0; i <= p; i++) {
    if (M[i].size() > 1) {
      cout << M[i][0] << "-" << M[i][M[i].size() - 1];
    } else if (M[i].size() == 1) {
      cout << M[i][0];
    }
    if (i < p) cout << ",";
  }
  cout << endl;
}
int main() {
  int t;
  solve();
}
