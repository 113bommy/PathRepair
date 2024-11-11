#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<string> vec(n);
    vector<int> cnt(26);
    for (int i = 0; i < n; i++) {
      cin >> vec[i];
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < vec[i].size(); j++) {
        cnt[vec[i][j] - 'a']++;
      }
    }
    bool check = 0;
    for (int i = 0; i < 26; i++) {
      if (cnt[i] % n != 0) {
        check = 1;
        break;
      }
    }
    if (check) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
}
