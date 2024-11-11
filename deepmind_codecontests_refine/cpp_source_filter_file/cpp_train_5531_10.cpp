#include <bits/stdc++.h>
using namespace std;
template <typename T>
void out(T x) {
  cout << x << endl;
  exit(0);
}
const int maxn = 1e6 + 7;
int n;
int m;
set<pair<int, int>> have;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    have.insert({a, b});
    have.insert({b, a});
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; i++) {
      if (!have.count({i, j})) {
        cout << "YES\n";
        int idx = 3;
        for (int k = 0; k < n; k++) {
          if (k == i)
            cout << 1 << " ";
          else if (k == j)
            cout << 2 << " ";
          else
            cout << idx++ << " ";
        }
        cout << "\n";
        idx = 3;
        for (int k = 0; k < n; k++) {
          if (k == i)
            cout << 1 << " ";
          else if (k == j)
            cout << 1 << " ";
          else
            cout << idx++ << " ";
        }
        cout << "\n";
        return 0;
      }
    }
  }
  out("NO");
  return 0;
}
