#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int a[105][105];
  memset(a, 0, sizeof(a));
  int k;
  cin >> k;
  for (int i = 0; i < k; i++) {
    int q, w;
    cin >> q >> w;
    q--;
    w--;
    a[q][w]++;
  }
  int count = 0;
  for (int i = 3; i < n - 3; i++)
    for (int j = 3; j < m - 3; j++) count += a[i][j];
  if (count == k)
    cout << "NO";
  else
    cout << "YES";
  return 0;
}
