#include <bits/stdc++.h>
using namespace std;
bool f[100005];
int main() {
  int n, c, nr = 0, mx = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> c;
    nr--;
    if (f[c] == false) {
      nr += 2;
      f[c] = 1;
      mx = max(nr, mx);
    }
  }
  cout << mx;
  return 0;
}
