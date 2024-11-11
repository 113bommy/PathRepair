#include <bits/stdc++.h>
using namespace std;
int a[200000 + 5];
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  int t = n;
  bool l = 0, r = 0;
  for (int i = n - 1; i > 0; --i) {
    if (a[i] == 1) r = 1;
    if (a[i] == 0) l = 1;
    if (r && l) {
      t = i + 1;
      break;
    }
  }
  cout << t << endl;
}
