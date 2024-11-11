#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int a, b;
  cin >> a >> b;
  int i = 0;
  while (a < b) a *= 3, b *= 2, i++;
  cout << i;
}
