#include <bits/stdc++.h>
using namespace std;
int main() {
  int N[5];
  map<string, int> mp;
  for (int i = 0; i < 5; i++) {
    cin >> N[i];
  }
  mp["S"] = 0;
  mp["M"] = 1;
  mp["L"] = 2;
  mp["XL"] = 3;
  mp["XXL"] = 4;
  string lt[5] = {"S", "M", "L", "XL", "XXL"};
  int n;
  cin >> n;
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    int p = mp[s];
    int ans;
    for (int d = 0;; d++) {
      if (p + d > 0 && p + d < 5) {
        if (N[p + d] > 0) {
          ans = p + d;
          break;
        }
      }
      if (p - d > 0 && p - d < 5) {
        if (N[p - d] > 0) {
          ans = p - d;
          break;
        }
      }
    }
    N[ans]--;
    cout << lt[ans] << endl;
  }
  return 0;
}
