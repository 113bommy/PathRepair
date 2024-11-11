#include <bits/stdc++.h>
using namespace std;
int a[100010], b[100010], o[100010];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
    o[a[i]] = b[i];
  }
  for (int i = 1; i <= n; ++i) {
    if (i != 1) cout << ' ';
    cout << o[i];
  }
  cout << endl;
  return 0;
}
