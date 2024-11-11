#include <bits/stdc++.h>
using namespace std;
int Ans[101];
int main() {
  int n, m, i, j, a, ck;
  cin >> n >> m;
  ck = n;
  for (i = 0; i < m; i++) {
    cin >> a;
    for (j = a; j <= ck; j++) Ans[j] = a;
    ck = a - 1;
  }
  for (i = 1; i <= n; i++) cout << Ans[i] << ' ';
  return 0;
}
