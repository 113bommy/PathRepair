#include <bits/stdc++.h>
const unsigned int M = 1000000007;
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, r = 0, both = 0, b = 0, k, ans;
  cin >> n;
  int a[2][n];
  for (int i = 0; i < n; i++) {
    cin >> a[0][i];
  }
  for (int i = 0; i < n; i++) {
    cin >> a[1][i];
  }
  for (int i = 0; i < n; i++) {
    if (a[0][i] == 1 && a[1][i] == 1)
      both++;
    else if (a[0][i] == 1 && a[1][i] == 0)
      r++;
    else if (a[0][i] == 0 && a[1][i] == 1)
      b++;
  }
  if (r == 0 && b != 0)
    ans = -1;
  else if (r == 0 && b == 0)
    ans = -1;
  else if (r == b && r != 0)
    ans = 2;
  else if (r > b)
    ans = 1;
  else {
    ans = b / r + 1;
  }
  cout << ans;
}
