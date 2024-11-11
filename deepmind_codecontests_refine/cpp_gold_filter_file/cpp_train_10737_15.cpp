#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  vector<int> v(t, 0);
  for (int i = 0; i < t; i++) {
    cin >> v[i];
  }
  int x = v[0] % 2, c = 1, c2 = 0, max = 0, l;
  for (int i = 1; i < t; i++) {
    if (v[i] % 2 == x) {
      c++;
      continue;
    } else {
      x = (x + 1) % 2;
      l = 2 * min(c, c2);
      c2 = c;
      c = 1;
      if (l > max) max = l;
    }
  }
  l = 2 * min(c, c2);
  if (l > max) max = l;
  cout << max;
}
