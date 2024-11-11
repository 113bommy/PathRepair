#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int x, y, z, t1, t2, t3;
  cin >> x >> y >> z >> t1 >> t2 >> t3;
  int l = abs(x - y);
  int ll = abs(x - z);
  if (l * t1 < l * t2 + 2 * t3 + ll * t2)
    cout << "NO\n";
  else
    cout << "YES\n";
  return 0;
}
