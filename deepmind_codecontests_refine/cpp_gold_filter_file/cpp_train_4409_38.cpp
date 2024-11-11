#include <bits/stdc++.h>
using namespace std;
int main() {
  ios ::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  string s[n];
  for (auto &i : s) {
    cin >> i;
  }
  for (int i = 0; i < n; i++) {
    int star = 0;
    for (int j = 0; j < m; j++) {
      if (s[i][j] == '*') {
        star++;
      }
    }
    if (star == 1) {
      cout << i + 1;
      break;
    }
  }
  cout << " ";
  for (int i = 0; i < m; i++) {
    int star = 0;
    for (int j = 0; j < n; j++) {
      if (s[j][i] == '*') {
        star++;
      }
    }
    if (star == 1) {
      cout << i + 1;
      break;
    }
  }
}
