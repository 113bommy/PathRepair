#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s, z;
  cin >> s >> z;
  int cnt = 0;
  for (int i = 0; i < n / 2; i++) {
    int letters[26] = {0};
    letters[z[i] - 'a']++;
    letters[z[n - i - 1] - 'a']++;
    letters[s[i] - 'a']++;
    letters[s[n - i - 1] - 'a']++;
    vector<int> v;
    for (int j = 0; j < 26; j++)
      if (letters[j] != 0) v.push_back(letters[j]);
    if (v.size() == 1) {
    } else {
      if (v.size() == 4) {
        cnt += 2;
      } else {
        if (v.size() == 2) {
          if (v[0] == v[1]) {
          } else {
            cnt += 1;
          }
        } else {
          if (s[i] == s[n - i + 1]) {
            cnt += 2;
          } else
            cnt += 1;
        }
      }
    }
  }
  if (n % 2 == 1) {
    if (s[n / 2] != z[n / 2]) cnt++;
  }
  cout << cnt << endl;
  return 0;
}
