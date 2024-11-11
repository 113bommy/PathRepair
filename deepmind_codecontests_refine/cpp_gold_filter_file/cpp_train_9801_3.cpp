#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n;
  long long int sum = 0;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < m; i++) {
    sum -= a[n - b[i]];
    cout << sum << endl;
    sum += a[n - b[i]];
  }
}
