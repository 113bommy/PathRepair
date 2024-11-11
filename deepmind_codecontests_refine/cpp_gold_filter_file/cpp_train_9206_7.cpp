#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a[20101], b[20101], n, m, sum = 0, e, d;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) {
    cin >> e >> d;
    sum += min(a[e - 1], a[d - 1]);
  }
  cout << sum;
}
