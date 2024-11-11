#include <bits/stdc++.h>
using namespace std;
string s;
int k;
bool vis[35];
struct Node {
  int id;
  int num;
  friend bool operator<(const Node n1, const Node n2) {
    if (n1.num != n2.num)
      return n1.num > n2.num;
    else
      return n1.id < n2.id;
  }
} p[35];
int main() {
  cin >> s >> k;
  int len = s.size();
  if (k >= len) {
    cout << "0" << endl << endl;
    return 0;
  } else {
    memset(vis, false, sizeof vis);
    for (int i = 0; i < len; i++) {
      int k = s[i] - 'a';
      p[k].id = k;
      p[k].num++;
    }
    sort(p, p + 26);
    int sum = 0, hehe;
    for (int i = 26; i >= 0; i--) {
      int num = p[i].num;
      if (num == 0) continue;
      sum += num;
      if (sum <= k) {
        vis[p[i].id] = true;
      } else {
        hehe = i;
        break;
      }
    }
    int res = 0;
    for (int i = 0; i <= hehe; i++) {
      if (p[i].num) res++;
    }
    cout << res << endl;
    for (int i = 0; i < len; i++) {
      int m = s[i] - 'a';
      if (!vis[m]) {
        cout << s[i];
      }
    }
    cout << endl;
  }
  return 0;
}
