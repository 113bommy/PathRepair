#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int i, j, a[m], b[m], c[m];
  for (i = 0; i < m; i++) {
    cin >> a[i] >> b[i] >> c[i];
  }
  int owe[n + 1];
  memset(owe, 0, sizeof(owe));
  for (i = 0; i < m + 1; i++) {
    owe[a[i]] -= c[i];
    owe[b[i]] += c[i];
  }
  int sum = 0;
  for (i = 0; i < n + 1; i++) {
    if (owe[i] > 0) {
      sum = sum + owe[i];
    }
  }
  cout << sum << endl;
}
