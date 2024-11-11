#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
template <class T>
T abs(T x) {
  return x > 0 ? x : -x;
}
int n;
string s[30];
map<string, pair<int, pair<int, int> > > m;
int num(string str) {
  int ans = 0;
  for (int i = 0; i < (n); i++) {
    for (int j = 0; j < (((int)(s[i]).size()) - ((int)(str).size()) + 1); j++) {
      int g = 1;
      for (int k = 0; k < (((int)(str).size())); k++)
        if (str[k] != s[i][j + k]) {
          g = 0;
          break;
        }
      if (g) {
        ans++;
        break;
      }
    }
  }
  return ans;
}
pair<int, pair<int, int> > make(int a, int b, int c) {
  return make_pair(a, make_pair(b, c));
}
pair<int, pair<int, int> > getans(string s) {
  if (m.count(s)) return m[s];
  pair<int, pair<int, int> > ans = make(0, 0, 0);
  for (int i = 0; i < (52); i++) {
    string tmp;
    if (i >= 26) {
      tmp = s;
      tmp += "o";
      tmp[((int)(tmp).size()) - 1] = (char)(i + 'a' - 26);
    } else {
      tmp = "o" + s;
      tmp[0] = (char)(i + 'a');
    }
    int z = num(tmp);
    if (z) {
      pair<int, pair<int, int> > o = getans(tmp);
      int bonus = 0;
      int bm = 0;
      for (int j = 0; j < (((int)(tmp).size())); j++) {
        bm = max(bm, (int)(tmp[j] - 'a' + 1));
        bonus += tmp[j] - 'a' + 1;
      }
      bonus *= bm;
      bonus += z;
      ans = max(ans,
                make(1 ^ o.first, -o.second.second + bonus, -o.second.first));
    }
  }
  m[s] = ans;
  return ans;
}
int main() {
  cin >> n;
  for (int i = 0; i < (n); i++) cin >> s[i];
  sort(s, s + n);
  pair<int, pair<int, int> > tmp = getans("");
  if (tmp.first == 0)
    cout << "First" << endl;
  else
    cout << "Second" << endl;
  cout << tmp.second.first << ' ' << -tmp.second.second << endl;
  return 0;
}
