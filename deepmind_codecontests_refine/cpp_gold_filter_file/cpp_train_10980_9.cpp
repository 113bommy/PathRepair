#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int arr[26] = {0};
  string s;
  cin >> n;
  cin >> s;
  map<int, int> m;
  for (int i = 0; i < 26; i++) {
    m.insert({i, i - 32});
  }
  int count = 0;
  for (int i = 0; i <= 2 * n - 4; i = i + 2) {
    arr[s[i] - 'a']++;
    if (m[s[i] - 'a'] != s[i + 1] - 'a') {
      if (arr[s[i + 1] - 'a' + 32] > 0) {
        arr[s[i + 1] - 'a' + 32]--;
      } else {
        count++;
      }
    }
    if (m[s[i] - 'a'] == s[i + 1] - 'a') {
      arr[s[i] - 'a']--;
    }
  }
  cout << count;
  return 0;
}
