#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  long long int i, x, j;
  long long int b[6] = {4, 8, 15, 16, 23, 42}, a[n];
  vector<long long int> v[45];
  for (i = 0; i < n; i++) {
    cin >> a[i];
    v[a[i]].push_back(i);
  }
  long long int c = 0;
  long long int vp[6] = {0};
  for (i = 0; i < v[b[0]].size(); i++) {
    long long int pos = v[b[0]][i];
    long long int f = 0;
    for (j = 1; j < 6; j++) {
      long long int m = v[b[j]].size(), k;
      for (k = vp[j]; k < m; k++)
        if (v[b[j]][k] > pos) break;
      if (k == m) {
        f = 1;
        break;
      } else {
        pos = v[b[j]][k];
        vp[j] = k + 1;
      }
    }
    if (f == 0) c++;
    if (f) break;
  }
  cout << n - 6 * c;
  return 0;
}
