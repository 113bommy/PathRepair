#include <bits/stdc++.h>
using namespace std;
map<string, string> mp;
int main() {
  int n, m;
  string a, b;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a >> b;
    mp[b] = a;
  }
  for (int i = 1; i <= m; i++) {
    cin >> a >> b;
    cout << a << " " << b << "; #" << mp[b] << endl;
  }
  return 0;
}
