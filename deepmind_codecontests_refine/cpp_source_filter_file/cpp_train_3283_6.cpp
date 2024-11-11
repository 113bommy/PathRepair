#include <bits/stdc++.h>
using namespace std;
bool isfile(string &s, int ind) {
  for (int i = ind;; i++) {
    if (s[i] == '.') return 1;
    if (s[i] == '\\') return 0;
  }
}
string getname(string &s, int ind) {
  string res = "";
  int i = ind;
  while (i < s.size() && s[i] != '\\') {
    res += s[i];
    i++;
  }
  return res;
}
struct p {
  map<string, int> m;
  int f;
  int pap;
  p() {
    f = 0;
    pap = 0;
  }
};
vector<p> V(5);
int dfs(int a) {
  int r = 0;
  for (map<string, int>::iterator it = V[a].m.begin(); it != V[a].m.end();
       it++) {
    r += dfs(it->second);
  }
  V[a].pap = r + V[a].m.size();
  return r + V[a].m.size();
}
int main() {
  vector<string> m;
  string ts;
  while (cin >> ts) {
    m.push_back(ts);
  }
  for (int i = 0; i < m.size(); i++) {
    int ind = 3, pl = m[i][0] - 'C';
    while (ind < m[i].size()) {
      if (isfile(m[i], ind)) {
        V[pl].f++;
        string name = getname(m[i], ind);
        ind += name.size() + 1;
      } else {
        string name = getname(m[i], ind);
        ind += name.size() + 1;
        if (V[pl].m.count(name)) {
          V[pl].f++;
          pl = V[pl].m[name];
        } else {
          p temp;
          V.push_back(temp);
          V[pl].f++;
          V[pl].m.insert(make_pair(name, V.size() - 1));
          pl = V.size() - 1;
        }
      }
    }
  }
  int m1 = -1, m2 = -1;
  dfs(0);
  dfs(1);
  dfs(2);
  dfs(3);
  dfs(4);
  for (int i = 1; i < V.size(); i++) {
    m1 = max(m1, V[i].f);
    m2 = max(m2, V[i].pap);
  }
  cout << m2 << ' ' << m1;
  return 0;
}
