#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> s;
  sort(s.begin(), s.end());
  reverse(s.begin(), s.end());
  for (int i = 0; i < s.size() - 1; i++) {
    cout << s[i];
    if (s[i] != s[i + 1]) return 0;
  }
}
