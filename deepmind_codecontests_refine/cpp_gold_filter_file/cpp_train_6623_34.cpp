#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, n, m, s = 0, x;
  cin >> t >> n >> m;
  for (int i = 0; i < t - n; i++) {
    cin >> x;
    s += x;
  }
  cout << s + m * n << endl;
  return 0;
}
