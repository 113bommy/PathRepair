#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string temp[n];
    map<char, int> m;
    for (int i = 0; i < n; i++) cin >> temp[i];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < temp[i].length(); j++) {
        m[temp[i][j]]++;
      }
    }
    int flag = 1;
    for (auto x : m) {
      if (x.second % n != 0) flag = 0;
    }
    if (flag)
      cout << "YES";
    else {
      cout << "NO";
    }
  }
}
