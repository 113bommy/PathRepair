#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    char x = s[0];
    bool f = 0;
    for (int j = 1; j < s.size(); j++)
      if (s[j] != x) f = 1;
    if (!f)
      cout << "-1\n";
    else {
      sort(s.begin(), s.end());
      cout << s << '\n';
    }
  }
}
