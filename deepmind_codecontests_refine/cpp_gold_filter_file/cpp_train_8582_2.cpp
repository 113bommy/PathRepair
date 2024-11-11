#include <bits/stdc++.h>
using namespace std;
string s[] = {"vaporeon", "jolteon", "flareon", "espeon",
              "umbreon",  "leafeon", "glaceon", "sylveon"};
int n;
string z;
int main() {
  cin >> n;
  cin >> z;
  int ans = -1;
  int indice = 0;
  for (int i = 0; i < 8; i++) {
    if (s[i].size() == z.size()) {
      int cnt = 0;
      for (int j = 0; j < s[i].size(); j++)
        if (s[i][j] == z[j]) cnt++;
      if (cnt > ans) {
        ans = cnt;
        indice = i;
      }
    }
  }
  cout << s[indice];
  return 0;
}
