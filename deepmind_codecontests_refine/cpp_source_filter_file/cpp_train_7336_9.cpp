#include <bits/stdc++.h>
using namespace std;
string s, t;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> s >> t;
  for (int i = s.length() - 1; i >= 0; i--) {
    if (s[i] + 1 < 'z') {
      s[i] = s[i] + 1;
      break;
    } else {
      s[i] = 'a';
    }
  }
  if (s < t) {
    cout << s;
  } else
    cout << "No such string";
}
