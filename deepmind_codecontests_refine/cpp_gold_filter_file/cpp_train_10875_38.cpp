#include <bits/stdc++.h>
using namespace std;
unsigned long long M = 1e9 + 7;
int b, m, k, tc;
int p, q, r, t;
string s;
int a[55][55];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  cin >> b >> m;
  for (int i = 0; i < (b); i++) {
    for (int j = 0; j < (m); j++) {
      cin >> a[i][j];
    }
  }
  cin >> p >> q;
  int mi = b * m;
  for (int i = 0; i <= b - q; i++) {
    for (int j = 0; j <= m - p; j++) {
      int sum = 0;
      for (int k = i; k < i + q; k++) {
        for (int l = j; l < j + p; l++) {
          sum += a[k][l];
        }
      }
      if (mi > sum) {
        mi = sum;
      }
    }
  }
  for (int i = 0; i <= b - p; i++) {
    for (int j = 0; j <= m - q; j++) {
      int sum = 0;
      for (int k = i; k < i + p; k++) {
        for (int l = j; l < j + q; l++) {
          sum += a[k][l];
        }
      }
      if (mi > sum) {
        mi = sum;
      }
    }
  }
  cout << mi << endl;
}
