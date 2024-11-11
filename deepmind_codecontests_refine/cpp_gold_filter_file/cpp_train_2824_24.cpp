#include <bits/stdc++.h>
using namespace std;
long long int b[100001];
signed main() {
  long long int n, x, y, c = 0, k = 0;
  cin >> n >> y;
  vector<long long int> a;
  for (long long int i = 0; i < n; i++) {
    cin >> x;
    a.push_back(x);
  }
  for (long long int i = 0; i < n - 1; i++) {
    if (a[i + 1] == a[i]) {
      b[k++] = c;
      c = 0;
    } else {
      c++;
      b[k] = c;
    }
  }
  long long int ans = *max_element(b, b + k + 1);
  cout << ans + 1;
}
