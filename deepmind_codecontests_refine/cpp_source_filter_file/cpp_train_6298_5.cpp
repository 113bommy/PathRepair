#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:64000000")
using namespace std;
int main() {
  int n, m, k;
  long long sum = 0, a[100001][3], b[1 << 10];
  cin >> n >> m >> k;
  for (int i = 0; i < m; ++i) cin >> a[i][0] >> a[i][1] >> a[i][2];
  for (int i = 0; i < k; ++i) cin >> b[i];
  for (int i = 0; i < k; ++i)
    for (int j = 0; j < m; ++j)
      if (a[j][0] <= b[i] && b[i] <= a[j][1]) sum += b[i] - a[j][0] + a[i][2];
  cout << sum;
  return 0;
  ;
  "         ";
  ;
  "  -   *  ";
  ;
  "    |    ";
  ;
  "  \___   ";
  ;
  "         ";
}
