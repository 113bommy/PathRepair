#include <bits/stdc++.h>
using namespace std;
struct arc {
  int a, b;
  char c;
  int ind;
  bool operator<(const arc &ot) const {
    return a < ot.a || a == ot.a && b > ot.b;
  }
};
arc s[111];
bool cmp(const arc &a, const arc &b) { return a.ind < b.ind; }
bool cross(arc a, arc b) {
  if (a.a > b.a) swap(a, b);
  return b.a < a.b && b.b > a.b && !(a.a == b.a) && !(a.b == b.b);
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    s[i].ind = i;
    cin >> s[i].a >> s[i].b;
    if (s[i].a > s[i].b) swap(s[i].a, s[i].b);
  }
  sort(s, s + m);
  for (int u = 0; u < m; u++) {
    if (s[u].c == 0) {
      queue<int> q;
      q.push(u);
      s[u].c = 'i';
      for (; !q.empty();) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < m; i++) {
          if (s[i].c == 0 && cross(s[i], s[cur])) {
            char other = s[cur].c == 'i' ? 'o' : 'i';
            bool can = true;
            for (int t = 0; t < m; t++) {
              if (s[t].c == other && cross(s[i], s[t])) {
                can = false;
              }
            }
            if (can) {
              s[i].c = other;
              q.push(i);
            } else {
              cout << "Impossible" << endl;
              return 0;
            }
          }
        }
      }
    }
  }
  sort(s, s + m, cmp);
  string str;
  for (int i = 0; i < m; i++) {
    str += s[i].c;
    if (s[i].c == 0) {
      cout << "Impossible" << endl;
      return 0;
    }
  }
  cout << str << endl;
  return 0;
}
