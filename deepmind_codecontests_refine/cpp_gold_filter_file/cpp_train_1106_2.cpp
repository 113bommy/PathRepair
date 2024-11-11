#include <bits/stdc++.h>
using namespace std;
const int maxn = 5050;
int k, n;
string s[maxn];
vector<int> pos;
bool was[26];
bool check() {
  vector<int> v;
  for (int i = 1; i < k; i++) {
    memset(was, false, sizeof(was));
    bool rep = false;
    v.clear();
    for (int j = 0; j < n; j++) {
      if (s[0][j] != s[i][j]) v.push_back(j);
      if (was[s[i][j] - 'a'])
        rep = true;
      else
        was[s[i][j] - 'a'] = true;
    }
    if ((v.size() != 0 && v.size() != 2) || (v.size() == 0 && !rep) ||
        (v.size() == 2 &&
         (s[0][v[0]] != s[i][v[1]] || s[0][v[1]] != s[i][v[0]])))
      return false;
  }
  return true;
}
int main() {
  cin >> k >> n;
  for (int i = 0; i < k; i++) cin >> s[i];
  int x = -1;
  for (int i = 1; i < k; i++) {
    if (s[i] != s[0]) {
      x = i;
      break;
    }
  }
  if (x == -1) {
    swap(s[0][0], s[0][1]);
    cout << s[0];
    return 0;
  }
  for (int i = 0; i < n; i++)
    if (s[0][i] != s[x][i]) pos.push_back(i);
  if (pos.size() > 4 || pos.size() == 1) return !printf("-1");
  for (int i = 0; i < pos.size(); i++) {
    for (int j = 0; j < n; j++) {
      if (pos[i] == j) continue;
      swap(s[0][pos[i]], s[0][j]);
      if (check()) {
        cout << s[0];
        return 0;
      }
      swap(s[0][pos[i]], s[0][j]);
    }
  }
  cout << "-1";
  return 0;
}
