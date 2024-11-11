#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> v(n);
  vector<int> p;
  for (int i = 0; i < n; i++) cin >> v[i];
  int x = 0, count = 0;
  while (x >= 0 && x < n && count <= n) {
    if (s[x] == '>')
      x += v[x];
    else
      x -= v[x];
    count++;
  }
  if (x < 0 || x >= n)
    cout << "FINITE\n";
  else
    cout << "INFINITE\n";
  return 0;
}
