#include <bits/stdc++.h>
using namespace std;
const int NMAX = 31;
int n;
int L[NMAX], C[NMAX];
int cnt;
int main() {
  int i, j, x;
  cin >> n;
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= n; ++j) {
      cin >> x;
      L[i] += x;
      C[j] += x;
    }
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= n; ++j)
      if (L[i] < C[j]) ++cnt;
  cout << cnt << "\n";
  return 0;
}
