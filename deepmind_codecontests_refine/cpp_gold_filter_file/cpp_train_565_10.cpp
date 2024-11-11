#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<char> v;
  v.resize(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  int x = 0;
  for (int i = 0; i < n; i++)
    if (v[i] == 'T') x++;
  int y, z = 0;
  for (int i = 0; i < n; i++) {
    y = 0;
    int q = 0;
    for (int j = i; q < x; q++) {
      if (v[j] == 'T') y++;
      j++;
      j %= n;
    }
    z = max(y, z);
  }
  cout << x - z;
  return 0;
}
