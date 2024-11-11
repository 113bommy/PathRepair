#include <bits/stdc++.h>
int a[1000][1000];
int compare(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
using namespace std;
int main() {
  int i, j, k, sum = 0, l, m, p, n;
  cin >> n >> p;
  m = n - p;
  int s = n * n;
  for (i = n; i > 0; i--)
    for (j = n; j >= p; j--) a[i][j] = s--;
  k = 1;
  for (i = 1; i <= n; i++)
    for (j = 1; j < p; j++) a[i][j] = k++;
  for (i = 1; i <= n; i++) sum += a[i][p];
  cout << sum << endl;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) cout << a[i][j] << " ";
    cout << endl;
  }
  return 0;
}
