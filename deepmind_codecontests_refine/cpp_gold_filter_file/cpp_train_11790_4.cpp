#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, x, y, z;
    cin >> n;
    y = n;
    map<int, int> mp;
    vector<int> v;
    int coun = 0;
    while (y--) {
      cin >> x;
      int f = 0;
      while (x--) {
        cin >> z;
        if (mp[z] == 0 && f == 0) {
          mp[z]++;
          coun++;
          f = 1;
        }
      }
      if (f == 0) v.push_back(n - y);
    }
    if (coun == n)
      cout << "OPTIMAL" << endl;
    else {
      cout << "IMPROVE" << endl;
      for (int i = 1; i <= n; i++) {
        if (mp[i] == 0) {
          cout << v[0] << " " << i << endl;
          break;
        }
      }
    }
  }
}
