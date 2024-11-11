#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int x;
  int y;
  vector<int> v;
  if (k > n) {
    cout << "NO"
         << "\n";
    return 0;
  }
  for (int i = 0; i < n; i++) {
    if (s[i] == 'G') x = i;
    if (s[i] == 'T') y = i;
    if (s[i] == '#') v.push_back(i);
  }
  if (abs(x - y) % k == 0) {
    for (int i = 0; i < v.size(); i++) {
      if (y > x) {
        if (v[i] > x && v[i] < y) {
          if (abs(x - v[i]) % k == 0) {
            cout << "NO"
                 << "\n";
            return 0;
          }
        }
      }
      if (x > y) {
        if (v[i] > y && v[i] < x) {
          if (abs(x - v[i]) % k == 0) {
            cout << "NO"
                 << "\n";
            return 0;
          }
        }
      }
    }
    cout << "YES"
         << "\n";
    return 0;
  }
  cout << "NO"
       << "\n";
  return 0;
}
