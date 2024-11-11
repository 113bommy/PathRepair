#include <bits/stdc++.h>
using namespace std;
int num[26] = {0};
int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  string t = s;
  sort(s.begin(), s.end());
  for (int i = 0; i < k; i++) {
    num[s[i] - 'a']++;
  }
  for (int i = 0; i < t.size(); i++) {
    if (num[t[i] - 'a']) {
      num[t[i] - 'a']--;
    } else {
      cout << t[i];
    }
  }
  return 0;
}
