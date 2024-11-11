#include <bits/stdc++.h>
using namespace std;
int n, m, a[21][21];
void swaps(int fir, int sec) {
  for (int i = 1; i <= n; ++i) {
    swap(a[i][fir], a[i][sec]);
  }
}
bool checksol() {
  for (int i = 1; i <= n; ++i) {
    int ans = 0;
    for (int j = 1; j <= m; ++j) {
      if (a[i][j] != j) {
        ++ans;
      }
    }
    if (ans >= 3) {
      return false;
    }
  }
  return true;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= m; ++i) {
    for (int j = i + 1; j <= m; ++j) {
      swaps(i, j);
      if (checksol()) {
        cout << "YES";
        return 0;
      } else
        swaps(i, j);
    }
  }
  cout << "NO";
  return 0;
}
