#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
int main() {
  ios::sync_with_stdio(false);
  int x, y, z, t1, t2, t3;
  cin >> x >> y >> z >> t1 >> t2 >> t3;
  long long int ans1, ans2;
  ans1 = t1 * abs(x - y);
  ans2 = abs(z - x) * t2 + 3 * t3 + abs(x - y) * t2;
  if (ans2 < ans1)
    cout << "YES";
  else
    cout << "NO";
}
