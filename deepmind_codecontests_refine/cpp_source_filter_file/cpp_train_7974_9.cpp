#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  long long n, m;
  cin >> n >> m;
  int a[51][51];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> a[i][j];
  long long ats = 0;
  for (int i = 0; i < n; i++) {
    long long ones = 0;
    for (int j = 0; j < m; j++)
      if (a[i][j] == 1) ones++;
    ats += (1LL << ones) - 1 + (1LL << (m - ones)) - 1;
  }
  for (int j = 0; j < m; j++) {
    long long ones = 0;
    for (int i = 0; i < m; i++)
      if (a[i][j] == 1) ones++;
    ats += (1LL << ones) - 1 + (1LL << (n - ones)) - 1;
  }
  cout << ats - n * m;
  return 0;
}
