#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  char str[100];
  for (int i = 1; i <= n; i++) cin >> str[i];
  for (int j = 0; j < m; j++) {
    int l, r;
    char c1, c2;
    cin >> l >> r >> c1 >> c2;
    for (int k = l; k <= r; k++) {
      if (str[k] == c1) str[k] = c2;
    }
  }
  for (int g = 1; g <= n; g++) cout << str[g];
}
