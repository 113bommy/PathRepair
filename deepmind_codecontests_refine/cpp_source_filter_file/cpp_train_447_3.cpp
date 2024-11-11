#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[100][100];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> a[i][j];
  vector<int> cow(100);
  vector<int> row(100);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      cow[i] += a[i][j];
      row[j] += a[i][j];
    }
  int ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      if (cow[i] > row[j]) ans++;
    }
  cout << ans;
  ans++;
}
