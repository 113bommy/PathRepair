#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string str[n];
  map<string, int> mp;
  for (int i = 0; i < n; i++) {
    cin >> str[i];
    if (!mp[str[i]]) mp[str[i]]++;
  }
  for (int i = n - 1; i >= 0; i--) {
    if (mp[str[i]] >= 1) cout << str[i] << endl;
    mp[str[i]]--;
  }
}
