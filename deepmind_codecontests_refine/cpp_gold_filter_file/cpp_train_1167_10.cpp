#include <bits/stdc++.h>
using namespace std;
struct node {
  long long int x;
  long long int y;
};
bool cmp(node n1, node n2) {
  if (n1.x != n2.x) {
    return n1.x < n2.x;
  } else {
    return n1.y < n2.y;
  }
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    node g[n];
    long long int i;
    for (i = 0; i < n; i++) {
      cin >> g[i].x;
      cin >> g[i].y;
    }
    sort(g, g + n, cmp);
    long long int x1 = 0;
    long long int y1 = 0;
    for (i = 0; i < n; i++) {
      if (x1 > g[i].x) {
        break;
      } else {
        x1 = g[i].x;
      }
      if (y1 > g[i].y) {
        break;
      } else {
        y1 = g[i].y;
      }
    }
    if (i == n) {
      cout << "YES\n";
      x1 = 0;
      y1 = 0;
      for (i = 0; i < n; i++) {
        while (g[i].x != x1) {
          cout << "R";
          x1++;
        }
        while (g[i].y != y1) {
          cout << "U";
          y1++;
        }
      }
    } else {
      cout << "NO";
    }
    cout << endl;
  }
}
