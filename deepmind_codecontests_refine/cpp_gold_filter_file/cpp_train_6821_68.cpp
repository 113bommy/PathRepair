#include <bits/stdc++.h>
using namespace std;
const long int m = 1000000007;
struct paint {
  long long int color, order;
};
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  map<int, paint> am;
  int i, j, x, y;
  long long int ch, rc, a;
  for (i = 0; i < k; i++) {
    cin >> ch >> rc >> a;
    if (ch == 1) {
      am[rc].color = a;
      am[rc].order = i;
    } else {
      am[rc + n].color = a;
      am[rc + n].order = i;
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      x = i + 1, y = j + 1;
      if (am[x].color == 0 || am[n + y].color == 0) {
        cout << am[x].color + am[n + y].color << " ";
      } else {
        if (am[x].order > am[n + y].order) {
          cout << am[x].color << " ";
        } else {
          cout << am[n + y].color << " ";
        }
      }
    }
    cout << endl;
  }
}
