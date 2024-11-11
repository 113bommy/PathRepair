#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long int n, m, *x, sum = 0, y, ans;
  cin >> n;
  x = new unsigned long long int[n];
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    sum += x[i];
  }
  sort(x, x + n);
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> y;
    cout << sum - x[n - y] << endl;
  }
}
