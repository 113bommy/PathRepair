#include <bits/stdc++.h>
using namespace std;
template <class T>
istream& operator>>(istream& stream, vector<T>& v) {
  for (T& x : v) {
    stream >> x;
  }
  return stream;
}
const int inf = 1000000000 + 7;
int a[100][100];
signed main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
    }
  int ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; ++j) {
      int vert = 0;
      int gor = 0;
      for (int k = 0; k < n; k++) {
        vert += a[i][k];
        gor += a[k][j];
      }
      if (vert < gor) ans++;
    }
  cout << ans;
}
