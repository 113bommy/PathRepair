#include <bits/stdc++.h>
using namespace std;
void write(vector<int> a) {
  for (auto x : a) {
    cout << x << ' ';
  };
  cout << endl;
}
void Isolve() {
  int n, m;
  cin >> n >> m;
  int mat[n][m];
  for (int i = (0); (1) > 0 ? i < (n) : i > (n); i += (1)) {
    for (int j = (0); (1) > 0 ? j < (m) : j > (m); j += (1)) {
      cin >> mat[i][j];
    }
  }
  int iout = 0;
  for (int i = (0); (1) > 0 ? i < (n / 2) : i > (n / 2); i += (1)) {
    for (int j = (0); (1) > 0 ? j < (m / 2) : j > (m / 2); j += (1)) {
      int a, b, x, y;
      a = mat[i][j];
      b = mat[i][m - j - 1];
      x = mat[n - i - 1][j];
      y = mat[n - i - 1][m - j - 1];
      vector<int> ioven;
      ioven.push_back(a);
      ioven.push_back(b);
      ioven.push_back(x);
      ioven.push_back(y);
      sort((ioven).begin(), (ioven).end());
      iout += ioven[3] + ioven[2] - ioven[1] - ioven[0];
    }
    if (m % 2) {
      iout += abs(mat[i][m / 2] - mat[n - i - 1][m / 2]);
    }
  }
  if (n % 2) {
    for (int i = (0); (1) > 0 ? i < (m / 2) : i > (m / 2); i += (1)) {
      iout += abs(mat[n / 2][i] - mat[n / 2][m - i - 1]);
    }
  }
  cout << iout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int it = 1;
  cin >> it;
  while (it--) {
    Isolve();
  }
  return 0;
}
