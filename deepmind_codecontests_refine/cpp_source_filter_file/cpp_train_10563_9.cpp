#include <bits/stdc++.h>
using namespace std;
const int N = 3100;
struct node {
  string a, b;
  node() {}
  node(string _a, string _b) : a(_a), b(_b) {}
} str[N];
string Min(int id) {
  int la = (int)str[id].a.size();
  int lb = (int)str[id].b.size();
  if (la < lb) return str[id].a;
  return str[id].b;
}
int main() {
  int n, m;
  while (cin >> n >> m) {
    for (int i = 1; i <= m; ++i) {
      string a, b;
      cin >> a >> b;
      node tmp(a, b);
      str[i] = tmp;
    }
    for (int i = 1; i <= n; ++i) {
      string c;
      cin >> c;
      string ans;
      for (int j = 1; j <= m; ++j)
        if (str[j].a == c) {
          ans = Min(j);
          break;
        }
      if (i == n)
        cout << ans << endl;
      else
        cout << ans << " ";
    }
  }
  return 0;
}
