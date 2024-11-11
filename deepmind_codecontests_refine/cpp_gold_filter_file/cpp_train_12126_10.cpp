#include <bits/stdc++.h>
using namespace std;
vector<int> st;
vector<vector<int> > gr;
vector<char> order;
bool sor(int x) {
  if (st[x] == 2) return false;
  if (st[x] == 1) return true;
  st[x] = 2;
  bool god = true;
  for (int ne : gr[x]) god = god && sor(ne);
  order.push_back('a' + x);
  st[x] = 1;
  return god;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  gr.resize(26);
  int n;
  string l, c;
  cin >> n >> l;
  bool good = true;
  n--;
  while (n--) {
    cin >> c;
    bool dif = false;
    for (int i = 0; i < min(l.size(), c.size()); i++) {
      if (l[i] != c[i]) {
        gr[c[i] - 'a'].push_back(l[i] - 'a');
        dif = true;
        break;
      }
    }
    if (!dif && l.size() > c.size()) {
      good = false;
      break;
    }
    l = c;
  }
  st.assign(26, 0);
  for (int i = 0; i < 26 && good; i++) {
    if (!st[i]) {
      bool work = sor(i);
      if (!work) good = false;
    }
  }
  if (good) {
    for (char c : order) cout << c;
    cout << endl;
  } else
    cout << "Impossible\n";
  return 0;
}
