#include <bits/stdc++.h>
using namespace std;
const long long int inf = 0x3f3f3f3f3f3f3f3fll;
const int maxx = INT_MAX;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  if (n == 1 && m == 1)
    cout << "YES"
         << "1" << endl;
  else if (n <= 2 && m <= 2)
    cout << "NO" << endl;
  else if (n == 3 && m == 3) {
    cout << "YES" << endl;
    cout << "8 3 4" << endl << "1 5 9" << endl << "6 7 2" << endl;
  } else if (n >= 4 || m >= 4) {
    cout << "YES" << endl;
    if (m >= 4) {
      vector<int> in[2];
      if (m % 2 == 0) {
        for (int i = 2; i <= m; i += 2) in[0].push_back(i);
        for (int i = 1; i <= m; i += 2) in[0].push_back(i);
        in[1] = in[0];
        reverse(in[1].begin(), in[1].end());
      } else {
        for (int i = 1; i <= 3; i++) {
          for (int j = i; j <= m; j += 3) in[0].push_back(j);
        }
        in[1] = in[0];
        swap(in[1][m / 2], in[1][0]);
        reverse(in[1].begin(), in[1].end());
      }
      for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) cout << (i - 1) * m + in[i % 2][j] << " ";
        cout << endl;
      }
    } else {
      vector<int> in[2];
      if (n % 2 == 0) {
        for (int i = 2; i <= n; i += 2) in[0].push_back(i);
        for (int i = 1; i <= n; i += 2) in[0].push_back(i);
        in[1] = in[0];
        reverse(in[1].begin(), in[1].end());
      } else {
        for (int i = 1; i <= 3; i++) {
          for (int j = i; j <= n; j += 3) in[0].push_back(j);
        }
        in[1] = in[0];
        swap(in[1][n / 2], in[1][0]);
        reverse(in[1].begin(), in[1].end());
      }
      for (int i = 0; i < n; i++) {
        for (int j = 1; j <= m; j++) cout << (in[j % 2][i] - 1) * m + j << " ";
        cout << endl;
      }
    }
  } else
    cout << "NO" << endl;
  return 0;
}
