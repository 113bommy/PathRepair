#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9;
const int mod = inf + 7;
const double eps = 1e-4;
const double pi = acos(-1.0);
int a[100100];
int n, m;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0) {
      for (int i = 0; i < m; ++i) cout << "#";
      cout << endl;
    }
    if (i % 4 == 1) {
      for (int i = 0; i < m - 1; ++i) cout << ".";
      cout << "#" << endl;
    }
    if (i % 4 == 3) {
      cout << "#";
      for (int i = 1; i < m; ++i) cout << ".";
      cout << endl;
    }
  }
}
