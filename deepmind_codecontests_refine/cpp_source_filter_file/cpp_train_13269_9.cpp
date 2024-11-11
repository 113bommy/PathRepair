#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, a[100005], b[100005] = {}, c[100005] = {};
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    b[a[i]]++;
  }
  for (i = 1; i < 100005; i++) {
    if (b[i + 1] > b[i]) {
      cout << -1;
      return 0;
    }
  }
  cout << b[1] << endl;
  for (i = 0; i < n; i++) {
    c[a[i]]++;
    cout << c[a[i]] << " ";
  }
}
