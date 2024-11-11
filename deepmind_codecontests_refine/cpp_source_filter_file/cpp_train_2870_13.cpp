#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, l, r;
  cin >> n >> m;
  int mn = 100005;
  for (int i = 0; i < n; i++) {
    cin >> l >> r;
    mn = min(mn, r - l + 1);
  }
  cout << mn << endl;
  for (int i = 0; i < n; i++) {
    cout << i % mn << ' ';
  }
}
