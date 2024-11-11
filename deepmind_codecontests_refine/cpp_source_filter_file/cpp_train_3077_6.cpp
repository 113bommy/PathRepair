#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, cnt;
  int i, ln, sz;
  string tx;
  vector<string> v;
  cin >> n;
  getchar();
  getline(cin, tx);
  ln = tx.size();
  int s = 0;
  for (i = 0; i < (ln); i++)
    if (tx[i] == '.' || tx[i] == '?' || tx[i] == '!') {
      v.push_back(tx.substr(s, i - s + 1));
      if (i + 1 < ln) s = i + 1;
    }
  cnt = sz = 0;
  for (i = 0; i < ((int)v.size()); i++) {
    if ((v[i][0] == ' ' && v[i].size() > n + 1) ||
        (v[i][0] != ' ' && v[i].size() > n)) {
      cout << "Impossible" << endl;
      return 0;
    }
    if (i > 0 && sz + (int)v[i].size() < n)
      sz += (int)v[i].size();
    else {
      sz = (v[i][0] == ' ') ? (int)v[i].size() - 1 : (int)v[i].size();
      cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}
