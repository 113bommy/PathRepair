#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << min(a, min(c, d)) * 256 + min((a - min(a, (c, d))), b) * 32;
}
