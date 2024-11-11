#include <bits/stdc++.h>
using namespace std;
int mas[21][21];
int n, m;
inline bool checkarr() {
  for (int i = 0; i < n; i++) {
    int wrongs = 0;
    for (int j = 0; j < m; j++) {
      if (mas[i][j] != j + 1) wrongs++;
      if (wrongs > 2) return false;
    }
  }
  return true;
}
inline void swapa(int a, int b) {
  for (int j = 0; j < n; j++) {
    int t = mas[j][a];
    mas[j][a] = mas[j][b];
    mas[j][b] = t;
  }
}
int main() {
  cin >> n >> m;
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cin >> mas[i][j];
    }
  }
  if (checkarr()) {
    cout << "YES";
    return 0;
  }
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      swapa(i, j);
      if (checkarr()) {
        cout << "YES";
        return 0;
      }
      swapa(i, j);
    }
  }
  cout << "NO";
  return 0;
}
