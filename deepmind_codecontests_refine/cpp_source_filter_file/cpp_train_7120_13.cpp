#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
char a[maxn + 10][maxn + 10];
vector<pair<int, int> > col, row;
int n;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> a[i][j];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (a[i][j] != 'E') {
        col.push_back(make_pair(i, j));
        j = n + 1;
      }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (a[i][j] != 'E') {
        row.push_back(make_pair(j, i));
        j = n + 1;
      }
  if (row.size() != n && col.size() != n)
    cout << -1 << endl;
  else {
    if (row.size() == n)
      for (int i = 0; i < n; i++)
        cout << row[i].first + 1 << " " << row[i].second + 1 << endl;
    else
      for (int i = 0; i < n; i++)
        cout << col[i].first + 1 << " " << col[i].second + 1 << endl;
  }
}
