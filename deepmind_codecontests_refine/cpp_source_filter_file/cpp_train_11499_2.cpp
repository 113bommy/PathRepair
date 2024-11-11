#include <bits/stdc++.h>
using namespace std;
set<int> v;
int main() {
  map<char, int> m;
  m['R'] = 6;
  m['G'] = 7;
  m['B'] = 8;
  m['Y'] = 9;
  m['W'] = 10;
  int n;
  scanf("%d", &n);
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    int x = 0;
    x |= (1 << m[s[0]]);
    x |= (1 << (s[1] - '1'));
    v.insert(x);
  }
  int ans = 10;
  for (int i = 0; i < 1 << 10; i++) {
    int f[10006] = {}, naa = 0;
    for (set<int>::iterator it = v.begin(); it != v.end(); it++) {
      if (f[i & *it]) {
        naa = 1;
        break;
      }
      f[i & *it]++;
    }
    if (!naa) ans = min(ans, __builtin_popcount(i));
  }
  cout << ans;
  return 0;
}
