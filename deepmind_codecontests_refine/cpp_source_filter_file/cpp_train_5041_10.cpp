#include <bits/stdc++.h>
using namespace std;
vector<int> tmp, last;
int n, i;
long long ans[28];
string s;
int main() {
  tmp.resize(28);
  last.resize(28);
  cin >> s;
  for (int i = 0; i <= 26; i++) {
    last[i] = -1;
  }
  for (int i = 0; i < s.length(); i++) {
    last[s[i] - 'a'] = i;
    for (int j = 0; j <= 26; j++) {
      tmp[j] = last[j];
    }
    sort(tmp.begin(), tmp.end() - 1);
    for (int j = 26; j; j--) {
      ans[26 - j + 1] += tmp[j] - tmp[j - 1];
    }
  }
  for (int i = 1; i <= 26; i++) {
    if (!ans[i]) {
      cout << i - 1 << endl;
      for (int j = 1; j < i; j++) cout << ans[j] << endl;
      return 0;
    }
  }
  cout << 25 << endl;
  for (int j = 1; j < 25; j++) cout << ans[j] << endl;
}
