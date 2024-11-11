#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b) {
  return (a.first < b.first) || (a.first == b.first && a.second > b.second);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  while (t--) {
    int n;
    cin >> n;
    int q;
    cin >> q;
    int a[3][n + 1];
    int d = 0;
    for (int i = 1; i <= n; i++) a[1][i] = 0, a[2][i] = 0;
    while (q--) {
      int r, c;
      cin >> r >> c;
      if (!a[r][c]) {
        a[r][c] = 1;
        if (r == 1) {
          if (c == n) {
            if (a[2][n - 1]) d++;
          } else {
            if (a[2][c]) d++;
            if (a[2][c - 1]) d++;
            if (a[2][c + 1]) d++;
          }
        } else {
          if (c == 1) {
            if (a[1][2]) d++;
          } else {
            if (a[1][c]) d++;
            if (a[1][c - 1]) d++;
            if (a[1][c + 1]) d++;
          }
        }
      } else {
        a[r][c] = 0;
        if (r == 1) {
          if (c == n) {
            if (a[2][n - 1]) d--;
          } else {
            if (a[2][c]) d--;
            if (a[2][c - 1]) d--;
            if (a[2][c + 1]) d--;
          }
        } else {
          if (c == 1) {
            if (a[1][2]) d--;
          } else {
            if (a[1][c]) d--;
            if (a[1][c - 1]) d--;
            if (a[1][c + 1]) d--;
          }
        }
      }
      if (d == 0)
        cout << "Yes" << endl;
      else
        cout << "No" << endl;
    }
  }
}
