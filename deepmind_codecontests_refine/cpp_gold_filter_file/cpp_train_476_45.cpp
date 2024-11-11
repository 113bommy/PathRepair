#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, v1, v2, t1, t2;
  cin >> n >> v1 >> v2 >> t1 >> t2;
  if (n * v1 + t1 * 2 < n * v2 + t2 * 2)
    cout << "First" << nl;
  else if (n * v1 + t1 * 2 > n * v2 + t2 * 2)
    cout << "Second" << nl;
  else
    cout << "Friendship" << nl;
}
