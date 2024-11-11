#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, i, c = 0, s = 0, m, a[200010], v[200010];
  cin >> n;
  cin >> m;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    v[a[i]]++;
  }
  for (i = 0; i < n - 1; i++) {
    v[a[i]] = v[a[i]] - 1;
    c += n - (i + 1) - v[a[i]];
  }
  cout << c;
  return 0;
}
