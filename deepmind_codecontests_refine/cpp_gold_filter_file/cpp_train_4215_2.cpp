#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > is_more(26, vector<int>(26, 0));
vector<bool> used(26, 0);
vector<string> name;
bool zapis(int a, int b, int x) {
  if (a >= b - 1) return 1;
  vector<bool> mam(26, 0);
  bool dakto = 0;
  int stav = -1, nstav, lastz = a;
  for (int y = a; y < b; y++) {
    if (name[y].size() > x) {
      dakto = 1;
      int cur = name[y][x] - 'a';
      mam[cur] = 1;
      for (int i = 0; i < 26; i++) {
        if (mam[i] && i != cur) is_more[cur][i] = 1;
      }
      nstav = cur;
    } else {
      if (dakto) return 0;
      nstav = -1;
    }
    if (nstav != stav) {
      if (!zapis(lastz, y, x + 1)) return 0;
      lastz = y;
    }
    stav = nstav;
  }
  if (!dakto) return 1;
  return zapis(lastz, b, x + 1);
}
int main() {
  int n;
  cin >> n;
  name.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> name[i];
  }
  if (!zapis(0, n, 0)) {
    cout << "Impossible" << endl;
    return 0;
  }
  vector<char> res;
  for (int i = 0; i < 26; i++) {
    bool ok = 0;
    for (int j = 0; j < 26; j++) {
      if (used[j]) continue;
      bool smallest = 1;
      for (int k = 0; k < 26; k++) {
        if (is_more[j][k] && !used[k]) {
          smallest = 0;
          break;
        }
      }
      if (smallest) {
        res.push_back(j + 'a');
        ok = 1;
        used[j] = 1;
        break;
      }
    }
    if (!ok) {
      cout << "Impossible" << endl;
      return 0;
    }
  }
  for (int i = 0; i < 26; i++) cout << res[i];
  cout << endl;
  return 0;
}
