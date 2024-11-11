#include <bits/stdc++.h>
using namespace std;
const int NN = 100005;
int main(int argc, char *argv[]) {
  int m;
  cin >> m;
  vector<vector<int> > vv(m);
  vector<int> table;
  for (int i = 0; i < m; ++i) {
    int t;
    cin >> t;
    if (t == 1) {
      int v;
      cin >> v;
      vv[i].push_back(v);
      if (table.size() < NN) table.push_back(v);
    } else {
      int l, c;
      cin >> l >> c;
      vv[i].push_back(l);
      vv[i].push_back(c);
      for (int j = 0; j < c && table.size() < NN; ++j) {
        for (int i = 0; i < l && table.size() < NN; ++i) {
          table.push_back(table[i]);
        }
      }
    }
  }
  int n;
  cin >> n;
  long long cnt = 0;
  int op = 0;
  for (int i = 0; i < n; ++i) {
    long long in;
    cin >> in;
    while (cnt < in) {
      if (vv[op].size() == 1) {
        ++cnt;
      } else {
        cnt += vv[op][0] * vv[op][1];
      }
      ++op;
    }
    if (in < table.size())
      cout << table[in - 1] << " ";
    else {
      if (vv[op - 1].size() == 1) {
        if (cnt == in) cout << vv[op - 1][0] << " ";
      } else {
        long long delta = vv[op - 1][0] * vv[op - 1][1];
        long long temp = cnt - delta;
        cout << table[(in - temp - 1) % vv[op - 1][0]] << " ";
      }
    }
  }
  cout << endl;
  return EXIT_SUCCESS;
}
