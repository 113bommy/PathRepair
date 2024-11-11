#include <bits/stdc++.h>
using namespace std;
class edge {
 public:
  int u;
  int v;
};
class vstate {
 public:
  int state;
  int v1;
  int v2;
  int vv;
};
int main() {
  int n;
  edge e[100001];
  int c[100001];
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> e[i].u >> e[i].v;
  }
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  vstate x;
  x.state = 0;
  for (int i = 0; i < n - 1; i++) {
    if (c[e[i].u - 1] != c[e[i].v - 1]) {
      if (x.state == 0) {
        x.state = 1;
        x.v1 = e[i].u;
        x.v2 = e[i].v;
      } else if (x.state == 1) {
        if (x.v1 == e[i].u || x.v1 == e[i].v) {
          x.state = 2;
          x.vv = x.v1;
        } else if (x.v2 == e[i].u || x.v2 == e[i].v) {
          x.state = 2;
          x.vv = x.v2;
        } else {
          x.state = 3;
          i = n;
        }
      } else if (x.state == 2) {
        if (e[i].u != x.vv && e[i].v != x.vv) {
          x.state = 3;
          i = n;
        }
      } else {
        x.state = 3;
        i = n;
      }
    }
  }
  if (x.state == 0)
    cout << "Yes\n" << 1 << endl;
  else if (x.state == 1)
    cout << "Yes\n" << x.v1 << endl;
  else if (x.state == 2)
    cout << "Yes\n" << x.vv << endl;
  else
    cout << "No\n";
  return 0;
}
