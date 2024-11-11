#include <bits/stdc++.h>
using namespace std;
int INP, AM, REACHEOF;
char BUF[(1 << 12) + 1], *inp = BUF;
const long double PI = acos((long double)-1.0);
string s;
struct Query {
  string a;
  int l, r;
} q[11];
int n;
int main() {
  ios ::sync_with_stdio(false);
  while (cin >> s) {
    cin >> n;
    for (int i = (1), _b = (n); i <= _b; i++) cin >> q[i].a >> q[i].l >> q[i].r;
    int l = s.length();
    set<string> all;
    for (int i = 0, _a = (l); i < _a; i++)
      for (int j = (i), _b = (l - 1); j <= _b; j++) {
        string t = s.substr(i, j - i + 1);
        bool ok = true;
        for (int x = (1), _b = (n); x <= _b; x++) {
          string r = q[x].a;
          int cnt = 0;
          for (int start = (0), _b = (r.length() - t.length() + 1); start <= _b;
               start++)
            if (r.substr(start, t.length()) == t) ++cnt;
          if (cnt < q[x].l || cnt > q[x].r) {
            ok = false;
            break;
          }
        }
        if (ok) all.insert(s);
      }
    cout << all.size() << endl;
  }
  return 0;
}
