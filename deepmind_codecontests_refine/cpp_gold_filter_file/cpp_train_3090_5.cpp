#include <bits/stdc++.h>
using namespace std;
int adj[1002][1002];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, a, b;
  cin >> n >> a >> b;
  if (a == 1 || b == 1) {
    if ((n == 2 || n == 3) && a == 1 && b == 1) {
      cout << "NO\n";
      return 0;
    }
    cout << "YES\n";
    int i = 1, j = 2;
    if (a >= b) {
      for (int k = a + 1; k <= n; k++) {
        adj[i][j] = 1;
        adj[j][i] = 1;
        i++;
        j++;
      }
      for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
          cout << adj[i][j];
        }
        cout << "\n";
      }
    } else {
      for (int k = b + 1; k <= n; k++) {
        adj[i][j] = 1;
        adj[j][i] = 1;
        i++;
        j++;
      }
      for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
          if (adj[i][j] || i == j)
            cout << 0;
          else
            cout << 1;
        }
        cout << "\n";
      }
    }
  } else
    cout << "NO\n";
}
