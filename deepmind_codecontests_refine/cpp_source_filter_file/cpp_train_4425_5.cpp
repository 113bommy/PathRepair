#include <bits/stdc++.h>
using namespace std;
struct mv {
  int a, b, c, id;
};
mv m[30000 * 4];
int c[30000];
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < 4 * n; i++) {
    cin >> m[i].a >> m[i].b >> m[i].c;
    m[i].a--;
    m[i].b--;
    m[i].c--;
    m[i].id = i + 1;
  }
  int nl = 4 * n;
  random_shuffle(m, m + nl);
  for (int i = nl; i--;) c[i] = 4;
  cout << "YES\n";
  while (nl > 0) {
    int onl = nl;
    for (int i = 0; i < nl; i++) {
      c[m[i].a]--;
      c[m[i].b]++;
      c[m[i].c]++;
      if (c[m[i].b] > 9 || c[m[i].c] > 9) {
        c[m[i].a]++;
        c[m[i].b]--;
        c[m[i].c]--;
      } else {
        cout << m[i].id << ' ';
        m[i] = m[nl - 1];
        i--;
        nl--;
      }
    }
    if (nl == onl) {
      cout << "stuck";
      break;
    }
  }
  return 0;
}
