#include <bits/stdc++.h>
using namespace std;
int main() {
  ifstream fin("Text.txt");
  int i = 0, j, q;
  int h, n, w, a, b, c, d, m, x, y, z, k, s = 0, t = 1, ans = 0;
  string st;
  cin >> n;
  vector<pair<int, int> > vc(n);
  vector<int> comps(n + 1), elems(n + 1), visited(n + 1);
  vector<list<int> > nb(n + 1, list<int>()), compsel(n + 1, list<int>());
  for (i = 0; i < n; i++) {
    scanf("%d", &a);
    elems[i + 1] = a;
    vc[i] = make_pair(a, i + 1);
  }
  sort(vc.begin(), vc.end());
  for (i = 0; i < n; i++) {
    nb[i + 1].push_back(vc[i].second);
    nb[vc[i].second].push_back(i + 1);
  }
  for (i = 0; i < n; i++) {
    if (!visited[i + 1]) {
      s++;
      queue<int> tr;
      tr.push(i + 1);
      while (!tr.empty()) {
        w = tr.front();
        comps[w] = s;
        visited[w] = 1;
        tr.pop();
        list<int>::iterator it = nb[w].begin();
        while (it != nb[w].end()) {
          if (!visited[*it]) {
            visited[*it] = 1;
            tr.push(*it);
          }
          it++;
        }
      }
    }
  }
  cout << s << endl;
  for (i = 0; i < n; i++) {
    compsel[comps[i + 1]].push_back(i + 1);
  }
  for (i = 0; i < n; i++) {
    if (!compsel[i + 1].empty()) {
      cout << compsel[i + 1].size() << " ";
      list<int>::iterator it = compsel[i + 1].begin();
      while (it != compsel[i + 1].end()) {
        cout << elems[*it] << " ";
        it++;
      }
      cout << endl;
    }
  }
  return 0;
}
