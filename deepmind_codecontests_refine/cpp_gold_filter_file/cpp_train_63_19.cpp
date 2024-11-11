#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  int mx = -1;
  for (int i = 0; i < n; ++i) {
    int tmp;
    cin >> tmp;
    if ((k % tmp) == 0) mx = max(mx, tmp);
  }
  cout << k / mx << '\n';
}
