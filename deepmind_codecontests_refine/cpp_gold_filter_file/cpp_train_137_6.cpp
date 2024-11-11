#include <bits/stdc++.h>
using namespace std;
int main() {
  int k;
  cin >> k;
  string s, s1 = "";
  cin >> s;
  std::vector<int> v(26);
  for (int i = 0; s[i]; i++) v[s[i] - 'a']++;
  for (int i = 0; i < 26; i++) {
    if (v[i] % k) {
      cout << "-1" << endl;
      return 0;
    }
  }
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < v[i] / k; j++) s1 += i + 'a';
  }
  for (int i = 0; i < k; i++) cout << s1;
  cout << endl;
}
