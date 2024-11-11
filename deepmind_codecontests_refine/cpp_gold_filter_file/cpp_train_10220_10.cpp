#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  for (int j = 0; j < q; j++) {
    int n;
    long long int k;
    cin >> n >> k;
    long long int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a, a + n);
    long long int mi, ma;
    mi = a[0];
    ma = a[n - 1];
    long long int diff = ma - mi;
    if (diff % 2 == 0)
      diff = diff / 2;
    else
      diff = diff / 2 + 1;
    if (k >= diff) {
      cout << mi + k << endl;
    } else
      cout << -1 << endl;
  }
}
