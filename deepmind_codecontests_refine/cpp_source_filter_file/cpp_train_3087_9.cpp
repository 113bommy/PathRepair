#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  string vowel = "aieou";
  bool a[256] = {};
  for (char c : vowel) a[c] = 1;
  for (int i = 0, j = 0; i < n; i = j) {
    cout << s[j++];
    if (a[s[i]])
      while (j < n && a[s[j]]) j++;
  }
}
