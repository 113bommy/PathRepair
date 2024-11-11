#include <bits/stdc++.h>
using namespace std;
int main() {
  int k[100];
  int a[100];
  int c, i, j, n, m;
  for (i = 0; i < 101; i++) {
    a[i] = 0;
    k[i] = 0;
  }
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    c = 0;
    for (j = 0; j < m; j++) {
      cin >> a[j];
      if (a[j] > a[c]) c = j;
    }
    k[c]++;
  }
  c = 0;
  for (i = 0; i < n; i++)
    if (k[c] < k[i]) c = i;
  cout << ++c;
}
