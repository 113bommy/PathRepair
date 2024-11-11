#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void amin(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
inline void amax(T &x, U y) {
  if (x < y) x = y;
}
signed main() {
  long long n, m;
  cin >> n >> m;
  long long matrice1[n][m];
  long long matrice2[n][m];
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      long long a;
      cin >> a;
      matrice1[i][j] = a;
    }
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      long long a;
      cin >> a;
      matrice2[i][j] = a;
    }
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      long long a = matrice1[i][j];
      long long b = matrice2[i][j];
      matrice1[i][j] = min(a, b);
      matrice2[i][j] = max(a, b);
    }
  }
  for (long long i = 1; i < n; i++) {
    for (long long j = 1; j < m; j++) {
      if (matrice1[i - 1][j] >= matrice1[i][j]) {
        cout << "Impossible";
        return 0;
      }
      if (matrice1[i][j - 1] >= matrice1[i][j]) {
        cout << "Impossible";
        return 0;
      }
      if (matrice2[i - 1][j] >= matrice2[i][j]) {
        cout << "Impossible";
        return 0;
      }
      if (matrice2[i][j - 1] >= matrice2[i][j]) {
        cout << "Impossible";
        return 0;
      }
    }
  }
  for (long long i = 1; i < n; i++) {
    if (matrice1[i - 1][0] >= matrice1[i][0]) {
      cout << "Impossible";
      return 0;
    }
    if (matrice2[i - 1][0] >= matrice2[i][0]) {
      cout << "Impossible";
      return 0;
    }
  }
  for (long long i = 1; i < m; i++) {
    if (matrice1[0][i - 1] >= matrice1[0][i]) {
      cout << "Impossible";
      return 0;
    }
    if (matrice2[0][i - 1] >= matrice2[0][i]) {
      cout << "Impossible";
      return 0;
    }
  }
  cout << "Possible";
  return 0;
}
