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
char a[101][101];
int main() {
  int n, k, cnt = 0;
  cin >> n >> k;
  int maxis = (n * n + 1) / 2;
  if (maxis < k)
    cout << "NO";
  else {
    cout << "YES\n";
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) a[i][j] = 'S';
    for (int i = 0; i < n; ++i) {
      if (i & 1) {
        for (int j = 1; j < n && cnt < k; j += 2) {
          a[i][j] = 'L';
          cnt++;
        }
      } else {
        for (int j = 0; j < n && cnt < k; j += 2) {
          a[i][j] = 'L';
          cnt++;
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) cout << a[i][j];
      cout << "\n";
    }
  }
  return 0;
}
