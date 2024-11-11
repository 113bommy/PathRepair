#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int i, c = 0, n;
  string s;
  cin >> n >> s;
  for (i = 0; i < s.size(); i++) {
    if (s[i] == '<')
      c++;
    else
      break;
  }
  for (i = s.size() - 1; i >= 0; i--) {
    if (s[i] == '>')
      c++;
    else
      break;
  }
  cout << c << endl;
}
