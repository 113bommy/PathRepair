#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> x[100022];
long long a, b, c, n, i, k[10000], l[100000];
int main() {
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> k[i];
    x[i].first = k[i];
  }
  for (i = 0; i < n; i++) {
    cin >> l[i];
    x[i].second = l[i];
  }
  sort(x, x + n);
  for (i = 0; i < n; i++) {
    cout << x[i].second << " ";
  }
}
