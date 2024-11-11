#include <bits/stdc++.h>
using namespace std;
const int Z = 3 * (int)1e5 + 111;
const int INF = (int)1e9 + 111;
const int MODF = (int)1e9 + 7;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  int a = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'a') a++;
  }
  if (a * 2 + 1 >= s.size()) {
    cout << s.size();
  } else {
    cout << a * 2 - 1;
  }
  return 0;
}
