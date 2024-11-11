#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  char alpha[26] = {0};
  for (int i = 0; i < s.length(); i++) {
    alpha[s[i] - 'a']++;
  }
  int cnt = 0;
  for (int i = 0; i < 36; i++) {
    if (alpha[i] != 0) {
      cnt++;
    }
  }
  if (cnt % 2) {
    cout << "IGNORE HIM!"
         << "\n";
  } else {
    cout << "CHAT WITH HER!"
         << "\n";
  }
}
