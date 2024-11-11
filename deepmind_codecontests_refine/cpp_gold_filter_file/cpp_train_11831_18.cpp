#include <bits/stdc++.h>
using namespace std;
template <typename T>
using V = vector<T>;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  int ans = 0;
  set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
  for (char c : s) {
    if (isalpha(c) && vowels.count(c)) ++ans;
    if (isdigit(c) && (c - '0') % 2 == 1) ++ans;
  }
  cout << ans << endl;
}
