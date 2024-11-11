#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x;
  cin >> n;
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    cin >> x;
    mp[x]++;
  }
  if (mp.size() == 2) {
    if (mp.begin()->second == n / 2) {
      cout << "YES\n";
      for (auto &x : mp) {
        cout << x.first << " ";
      }
    } else {
      cout << "NO";
    }
  } else {
    cout << "NO";
  }
}
