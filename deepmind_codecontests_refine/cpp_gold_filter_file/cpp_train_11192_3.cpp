#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m;
  cin >> n >> m;
  long long int a[n], b[m];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  for (int i = 0; i < m; i++) {
    cin >> b[i];
    cout << upper_bound(a, a + n, b[i]) - a << " ";
  }
}
