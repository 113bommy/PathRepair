#include <bits/stdc++.h>
using namespace std;
bool g[105][105];
int a[105][105];
int n, k;
void printGrid() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << a[i][j];
    }
    cout << endl;
  }
}
void printG() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << g[i][j];
    }
    cout << endl;
  }
}
int main() {
  cin >> n >> k;
  memset(a, 0, sizeof(a));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      char c;
      cin >> c;
      if (c == '.') {
        g[i][j] = true;
      } else {
        g[i][j] = false;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int x = 0;
      for (; x < k; x++) {
        if (i + x > n || !g[i + x][j]) {
          break;
        }
      }
      if (x == k) {
        for (int p = 0; p < k; p++) {
          a[i + p][j]++;
        }
      }
      x = 0;
      for (; x < k; x++) {
        if (j + x > n || !g[i][j + x]) {
          break;
        }
      }
      if (x == k) {
        for (int p = 0; p < k; p++) {
          a[i][j + p]++;
        }
      }
    }
  }
  int ans = -1;
  int ansi = 0;
  int ansj = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[i][j] > ans) {
        ans = a[i][j];
        ansi = i;
        ansj = j;
      }
    }
  }
  cout << ansi << " " << ansj;
}
