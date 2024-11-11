#include <bits/stdc++.h>
using namespace std;
int n, p, ans;
struct node {
  string a;
  char b;
} s[50];
queue<string> q;
map<unsigned long long, bool> vis;
inline unsigned long long Hash(string s) {
  int p = s.size();
  unsigned long long res = 0LL;
  for (int i = 0; i < p; ++i)
    res = (res * 26LL + (unsigned long long)(s[i] - 'a' + 1));
  return res;
}
inline bool check(string x) {
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < n - 1; ++j) {
      bool flg = 0;
      for (int k = 1; k <= p; ++k) {
        if (x[j] == s[k].a[0] && x[j + 1] == s[k].a[1]) {
          x.erase(j + 1, 1);
          x[j] = s[k].b;
          flg = 1;
          break;
        }
      }
      if (flg)
        break;
      else
        return 0;
    }
  }
  return 1;
}
int main() {
  cin >> n >> p;
  for (int i = 1; i <= p; ++i) cin >> s[i].a >> s[i].b;
  vis[Hash("a")] = 1;
  q.push("a");
  while (!q.empty()) {
    string x = q.front();
    q.pop();
    int len = x.size();
    for (int i = 0; i < len; ++i) {
      for (int k = 1; k <= p; ++k) {
        if (s[k].b == x[i]) {
          string t = x;
          t.erase(i, 1);
          t.insert(i, s[k].a);
          int H = Hash(t);
          if (!vis[H]) {
            vis[H] = 1;
            if ((int)t.size() < n) {
              q.push(t);
            }
            if ((int)t.size() == n && check(t)) {
              ans++;
            }
          }
        }
      }
    }
  }
  cout << ans;
  return 0;
}
