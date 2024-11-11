#include <bits/stdc++.h>
using namespace std;
class node {
 public:
  char c;
  int num;
  ;
  bool f;
};
bool cmp(node a, node b) { return a.num < b.num; }
bool cmp2(node a, node b) { return a.c < b.c; }
int main() {
  string ans;
  string s;
  int n, aa = 0;
  node t[27] = {};
  for (int i = 0; i < 27; ++i) {
    t[i].c = 'a' + i;
    t[i].num = 0;
    t[i].f = true;
  }
  cin >> s >> n;
  for (int i = 0; i < s.size(); ++i) {
    t[s[i] - 'a'].num++;
  }
  sort(t, t + 26, cmp);
  for (int i = 0; i < 26 && n; ++i) {
    if (t[i].num <= n) {
      n -= t[i].num;
      t[i].num = 0;
    }
  }
  sort(t, t + 26, cmp2);
  for (int i = 0; i < s.size(); ++i) {
    if (t[s[i] - 'a'].num) {
      ans.push_back(s[i]);
      if (t[s[i] - 'a'].f) {
        ++aa;
        t[s[i] - 'a'].f = false;
      }
    }
  }
  cout << aa << endl << ans << endl;
}
