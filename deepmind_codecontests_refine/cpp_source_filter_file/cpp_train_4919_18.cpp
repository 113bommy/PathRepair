#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t, i, j, k, l;
  char c;
  int n, s;
  cin >> n >> s;
  if (s > 2 * (n - 1)) {
    cout << "YES\n";
    for (i = 0, s -= 2 * (n - 1); i < n; i++) cout << (i != 0 ? 2 : s) << " ";
    cout << "\n1\n";
  } else
    cout << "NO\n";
  return 0;
}
