#include <bits/stdc++.h>
using namespace std;
int house[300010];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int a, b, c, d;
  for (int i = 0; i < n; ++i) cin >> house[i];
  a = house[0];
  d = house[n - 1];
  if (a != d) {
    cout << n - 1 << endl;
    return 0;
  }
  int i = 0;
  while (house[++i] == a)
    ;
  int j = n;
  while (house[--j] == d)
    ;
  cout << max(n - i - 1, j + 1 - 1) << endl;
}
