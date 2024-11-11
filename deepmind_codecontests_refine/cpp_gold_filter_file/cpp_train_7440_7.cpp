#include <bits/stdc++.h>
using namespace std;
vector<int> v[3844], w[3844], ans;
void dfs(int x) {
  while (!v[x].empty()) {
    int y = v[x].back();
    v[x].pop_back();
    dfs(y);
  }
  ans.push_back(x);
}
int main() {
  int n;
  cin >> n;
  map<char, int> mp;
  for (int i = 0; i < 26; i++) {
    mp['a' + i] = i;
  }
  for (int i = 0; i < 26; i++) {
    mp['A' + i] = i + 26;
  }
  for (int i = 0; i < 10; i++) {
    mp['0' + i] = i + 52;
  }
  int s0;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int a, b;
    a = mp[s[0]] * 62 + mp[s[1]], b = mp[s[1]] * 62 + mp[s[2]];
    if (i == 0) s0 = a;
    v[a].push_back(b);
    w[b].push_back(a);
  }
  bool no = 0;
  vector<int> c1, c2;
  for (int i = 0; i < 62 * 62; i++) {
    if (abs((int)(v[i].size()) - (int)(w[i].size())) > 1) {
      no = 1;
      break;
    } else if (((int)(v[i].size()) - (int)(w[i].size())) == 1) {
      c1.push_back(i);
    } else if (((int)(v[i].size()) - (int)(w[i].size())) == -1) {
      c2.push_back(i);
    }
  }
  if (!((c1.size() == 0 && c2.size() == 0) ||
        (c1.size() == 1 && c2.size() == 1)))
    no = 1;
  if (no) {
    cout << "NO" << endl;
    return 0;
  }
  if (c1.size()) {
    s0 = c1[0];
  }
  dfs(s0);
  reverse(ans.begin(), ans.end());
  string str;
  if (ans.size() != n + 1) {
    cout << "NO" << endl;
    return 0;
  } else {
    cout << "YES" << endl;
  }
  for (int i = 0; i < ans.size(); i++) {
    if (i == 0) {
      int x1 = ans[i] / 62, x2 = ans[i] % 62;
      if (x1 < 26) {
        str += ('a' + x1);
      } else if (x1 < 52) {
        str += ('A' + (x1 - 26));
      } else {
        str += ('0' + (x1 - 52));
      }
      if (x2 < 26) {
        str += ('a' + x2);
      } else if (x2 < 52) {
        str += ('A' + (x2 - 26));
      } else {
        str += ('0' + (x2 - 52));
      }
    } else {
      int x = ans[i] % 62;
      if (x < 26) {
        str += ('a' + x);
      } else if (x < 52) {
        str += ('A' + (x - 26));
      } else {
        str += ('0' + (x - 52));
      }
    }
  }
  cout << str << endl;
  return 0;
}
