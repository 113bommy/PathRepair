#include <bits/stdc++.h>
using namespace std;
const int MAXn = 1e6 + 10;
const int MAXnode = 2 * MAXn;
struct Node {
  int len, par, cnt;
  map<char, int> go;
};
Node node[MAXnode];
int last, cc;
void extendTree(char c) {
  int nw = cc++;
  node[nw].len = node[last].len + 1;
  node[nw].cnt = 1;
  int cur = last;
  while (cur != -1 && node[cur].go[c] == 0) {
    node[cur].go[c] = nw;
    cur = node[cur].par;
  }
  if (cur == -1) {
    node[nw].par = 0;
  } else {
    int next = node[cur].go[c];
    if (node[cur].len + 1 == node[next].len) {
      node[nw].par = next;
    } else {
      int clone = cc++;
      node[clone].par = node[next].par;
      node[clone].go = node[next].go;
      node[clone].len = node[cur].len + 1;
      node[nw].par = node[next].par = clone;
      while (cur != -1 && node[cur].go[c] == next) {
        node[cur].go[c] = clone;
        cur = node[cur].par;
      }
    }
  }
  last = nw;
}
void initTree() {
  last = cc++;
  node[last].par = -1;
}
bool mark[MAXn];
vector<int> byLen[MAXn];
int main() {
  ios::sync_with_stdio(false);
  initTree();
  string s;
  cin >> s;
  for (int i = 0; i < (int)s.size(); i++) extendTree(s[i]);
  for (int i = 0; i < cc; i++) byLen[node[i].len].push_back(i);
  for (int i = (int)s.size(); i >= 1; i--) {
    for (int j = 0; j < (int)byLen[i].size(); j++) {
      int v = byLen[i][j];
      node[node[v].par].cnt += node[v].cnt;
    }
  }
  int T;
  for (cin >> T; T > 0; T--) {
    string s;
    cin >> s;
    int n = s.size();
    s = s + s;
    int cur = 0;
    int L = 0, R = 0;
    vector<int> toClear;
    toClear.clear();
    int ans = 0;
    while (R < (int)s.size() && L <= R) {
      while (R < (int)s.size() && R - L < n) {
        if (node[cur].go.count(s[R]) == 0) break;
        cur = node[cur].go[s[R]];
        R++;
      }
      if (R - L == n) {
        if (!mark[cur]) {
          toClear.push_back(cur);
          mark[cur] = true;
          ans += node[cur].cnt;
        }
      }
      if (node[node[cur].par].len == R - L - 1) cur = node[cur].par;
      L++;
    }
    for (int i = 0; i < (int)toClear.size(); i++) mark[toClear[i]] = false;
    cout << ans << endl;
  }
  return 0;
}
