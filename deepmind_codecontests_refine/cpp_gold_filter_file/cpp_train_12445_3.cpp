#include <bits/stdc++.h>
using namespace std;
const int N = 509;
const long long oo = 100;
int a[N];
vector<int> b;
int n, m;
bool T[N][N], d[N][N];
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  d[0][0] = 1;
  T[0][0] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = m; j >= 0; j--) {
      if (d[i - 1][j]) d[i][j] = 1;
      if (j - a[i] >= 0 && d[i - 1][j - a[i]]) {
        d[i][j] = 1;
        for (int k = 0; k <= j; k++)
          T[j][k] =
              T[j][k] || (k >= a[i] && T[j - a[i]][k - a[i]]) || T[j - a[i]][k];
      }
    }
  for (int i = 0; i <= m; i++)
    if (T[m][i]) b.push_back(i);
  cout << b.size() << endl;
  for (int i = 0; i < b.size(); i++) cout << b[i] << ' ';
}
