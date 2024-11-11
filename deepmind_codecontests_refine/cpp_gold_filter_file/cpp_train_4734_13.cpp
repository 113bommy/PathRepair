#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  getline(cin, s);
  map<char, bool> vowels = {{'A', true}, {'E', true}, {'I', true},
                            {'O', true}, {'U', true}, {'Y', true}};
  for (int i = s.size(); i >= 0; i--) {
    if (isalpha(s[i])) {
      if (vowels[toupper(s[i])]) {
        cout << "YES"
             << "\n";
      } else {
        cout << "NO"
             << "\n";
      }
      return;
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
