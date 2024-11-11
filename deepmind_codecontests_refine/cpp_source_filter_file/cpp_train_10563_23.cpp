#include <bits/stdc++.h>
const int length = 6;
using namespace std;
int main() {
  map<string, string> mp;
  int x, y;
  cin >> x >> y;
  string n, m, q;
  for (int i = 0; i < y; i++) {
    cin >> n >> m;
    int ln = n.size();
    int lm = m.size();
    if (ln < lm)
      mp[n] = mp[m] = n;
    else
      mp[m] = mp[n] = m;
  }
  for (int i = 0; i < x; i++) {
    cin >> q;
    cout << mp[q] << " ";
  }
  return 0;
}
