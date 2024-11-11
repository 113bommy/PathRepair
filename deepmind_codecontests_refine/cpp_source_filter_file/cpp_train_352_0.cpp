#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  map<int, int> mp;
  int x[] = {2, 3, 5};
  int c;
  c = a;
  for (int i = 0; i < 3; i++) {
    while (c % x[i] == 0) {
      mp[x[i]]++;
      c /= x[i];
    }
  }
  mp[c]++;
  c = b;
  for (int i = 0; i < 3; i++) {
    while (c % x[i] == 0) {
      mp[x[i]]--;
      c /= x[i];
    }
  }
  mp[c]--;
  int ans = 0, check = 0;
  for (auto it : mp) {
    if (it.first == 2 or it.first == 3 or it.first == 3)
      ans += (abs(it.second));
    else if (it.second)
      check = 1;
  }
  cout << (check ? -1 : ans) << endl;
  return 0;
}
