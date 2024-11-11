#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  std::ios::sync_with_stdio(false);
  int x, check = 0;
  cin >> x;
  vector<int> v;
  int a[x];
  bool b = 0, ten = 0;
  for (int i = 0; i < x; i++) cin >> a[i];
  for (int i = 0; i < x; i++) {
    if (a[i] == 0 || a[i] == 100) {
      v.push_back(a[i]);
    } else if (a[i] > 9 && a[i] % 10 == 0 && !ten)
      v.push_back(a[i]), ten = 1;
    else if (a[i] < 10 && !b)
      v.push_back(a[i]), b = 1;
    else
      check = a[i];
  }
  if (!ten && !b && check != 0) v.push_back(check);
  cout << v.size() << endl;
  for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
}
