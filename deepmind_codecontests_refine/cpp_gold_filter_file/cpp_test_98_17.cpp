#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string str1, str2;
    cin >> str1 >> str2;
    int ans = 0, pos1 = 0, pos2 = 0;
    for (int i = 0; i < str2.length() - 1; i++) {
      for (int j = 0; j <= str1.length(); j++) {
        if (str2[i] == str1[j]) {
          pos1 = j;
        }
        if (str2[i + 1] == str1[j]) {
          pos2 = j;
        }
      }
      ans += abs(pos2 - pos1);
    }
    cout << ans << endl;
  }
}
