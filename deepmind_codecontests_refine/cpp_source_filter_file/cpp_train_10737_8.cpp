#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, i, j = 0, c = 0, t = 0, z = 0;
  cin >> x;
  int a[x];
  vector<int> v;
  for (i = 0; i < x; i++) {
    cin >> a[i];
  }
  for (i = 1; i < x; i++) {
    if (a[i - 1] == a[i])
      c++;
    else {
      v.push_back(c + 1);
      c = 0;
    }
  }
  if (c > 0) v.push_back(c + 1);
  for (int i = 0; i < v.size() - 1; i++) {
    z = max(min(v[i], v[i + 1]), z);
  }
  cout << z * 2;
  return 0;
}
