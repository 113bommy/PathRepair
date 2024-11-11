#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 10005;
int n, m, number;
int p[MAX_N], l, r, x, ile;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> l >> r >> x;
    ile = 0;
    number = p[x - 1];
    for (int j = l - 1; j < r; j++) {
      if (p[j] < number) {
        ile++;
      }
    }
    if (ile == x - l) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
}
