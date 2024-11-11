#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1 << 20;
int n;
bool gone[MAXN];
int anext[MAXN], aprev[MAXN];
int findnext(int i) {
  return (anext[i] != n && gone[anext[i]]) ? anext[i] = findnext(anext[i])
                                           : anext[i];
}
int findprev(int i) {
  return (aprev[i] != -1 && gone[aprev[i]]) ? aprev[i] = findprev(aprev[i])
                                            : aprev[i];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  set<int> cur, nxt;
  int i, sol = 0;
  cin >> s;
  n = s.size();
  for (i = 0; i < n; ++i) aprev[i] = i - 1, anext[i] = i + 1;
  for (i = 0; i < n; ++i)
    if ((i - 1 >= 0 && s[i - 1] != s[i]) || (i + 1 < n && s[i + 1] != s[i])) {
      cur.insert(i);
    }
  while (!cur.empty()) {
    ++sol;
    for (int i : cur) gone[i] = true;
    for (int i : cur) {
      if (findprev(i) != -1 && findnext(i) != n &&
          s[findprev(i)] != s[findnext(i)]) {
        nxt.insert(findprev(i));
        nxt.insert(findnext(i));
      }
    }
    cur = nxt;
    nxt.clear();
  }
  cout << sol << '\n';
}
