#include <bits/stdc++.h>
using namespace std;
struct triplet {
  int index, a, b;
};
bool comp(triplet &t1, triplet &t2) { return (t1.a < t2.a); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  int a[n][m], b[n][m];
  int x[n][m], y[n][m];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> a[i][j];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> b[i][j];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      x[i][j] = min(a[i][j], b[i][j]);
      y[i][j] = max(a[i][j], b[i][j]);
    }
  int chk = 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m - 1; j++)
      if (x[i][j] >= x[i][j + 1] || y[i][j] >= y[i][j + 1]) chk = 0;
  for (int i = 0; i < n - 1; i++)
    for (int j = 0; j < m; j++)
      if (x[i][j] >= x[i + 1][j] || y[i][j] >= y[i + 1][j]) chk = 0;
  if (chk)
    cout << "Possible";
  else
    cout << "Not Possible";
}
