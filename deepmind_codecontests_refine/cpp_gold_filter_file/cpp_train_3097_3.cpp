#include <bits/stdc++.h>
using namespace std;
int adj[1000][1000];
void f(int a[1000][1000]) {
  for (int i = 0; i < (1000); i++) {
    for (int j = 0; j < (1000); j++) {
      if (i != j) {
        a[i][j] = !a[i][j];
      }
    }
  }
}
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  if (a == 1 || b == 1) {
    if (a == b) {
      if (n == 1) {
        cout << "YES\n0\n";
      } else if (n == 2 || n == 3) {
        cout << "NO\n";
      } else {
        cout << "YES\n";
        for (int i = 0; i < (n - 1); i++) {
          adj[i][i + 1] = 1;
          adj[i + 1][i] = 1;
        }
        for (int i = 0; i < (n); i++) {
          for (int j = 0; j < (n); j++) {
            cout << adj[i][j];
          }
          cout << endl;
        }
      }
      return 0;
    }
    cout << "YES\n";
    for (int i = 1; i < (n - max(a, b) + 1); i++) {
      adj[i][0] = 1;
      adj[0][i] = 1;
    }
    if (a == 1) {
      f(adj);
    }
    for (int i = 0; i < (n); i++) {
      for (int j = 0; j < (n); j++) {
        cout << adj[i][j];
      }
      cout << endl;
    }
  } else {
    cout << "NO\n";
  }
}
