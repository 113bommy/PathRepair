#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int n, m;
int a[N][N];
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  int u = 1;
  while (u < (1 << 10)) {
    vector<int> zero, one, both;
    vector<int> k(N);
    for (int i = 0; i < n; i++) {
      bool o = false, z = false;
      for (int j = 0; j < m; j++) {
        if ((a[i][j] & u)) {
          o = true;
        } else {
          z = true;
        }
      }
      if (o && z) {
        both.push_back(i);
        k[i] = 2;
      } else if (o) {
        one.push_back(i);
        k[i] = 1;
      } else {
        zero.push_back(i);
        k[i] = 0;
      }
    }
    if ((one.size() % 2) || both.size() >= 1) {
      cout << "TAK" << endl;
      for (int i = 0; i < n; i++) {
        if (k[i] == 2) k[i] = 0;
      }
      if (!(one.size() % 2)) {
        k[both[0]] = 1;
      }
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if ((u & a[i][j]) && k[i]) {
            cout << j + 1 << " ";
            break;
          } else if (!(u & a[i][j]) && !k[i]) {
            cout << j + 1 << " ";
            break;
          }
        }
      }
      return 0;
    }
    u = u << 1;
  }
  cout << "NIE";
}
