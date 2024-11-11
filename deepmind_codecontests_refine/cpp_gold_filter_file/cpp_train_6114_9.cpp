#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, a[10], b[10], temp, i, j;
  cin >> n >> m;
  i = 0;
  while (i < n) {
    cin >> temp;
    a[i] = temp;
    ++i;
  }
  j = 0;
  while (j < m) {
    cin >> temp;
    b[j] = temp;
    ++j;
  }
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      if (a[i] == b[j]) cout << a[i] << ' ';
  return 0;
}
