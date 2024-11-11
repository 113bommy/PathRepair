#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s = "heidi";
  string t;
  cin >> t;
  int j = 0;
  for (int i = 0; i < t.size(); i++) {
    if (t[i] == s[j]) {
      j++;
      if (j == s.size() - 1) {
        cout << "YES" << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}
