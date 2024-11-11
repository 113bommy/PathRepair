#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n, m, z = 0;
  string s[25] = {};
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= i; j++)
      for (int k = 0; k < m; k++)
        for (int l = 0; l < k; l++) {
          bool y = 0;
          for (int g = j; g <= i; g++) {
            if (y) break;
            for (int h = l; h <= k; h++) {
              if (s[g][h] == '1') {
                y = 1;
                break;
              }
            }
          }
          if (!y) z = max(z, i - j + i - j + k - l + k - l + 4);
        }
  cout << z;
}
