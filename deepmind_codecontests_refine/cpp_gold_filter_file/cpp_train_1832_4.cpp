#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int cnt = 0;
  for (int i = 0, j = s.size() - 1; i < s.size(); i++, j--) {
    if (s[i] != s[j]) cnt++;
  }
  if (cnt == 2 || (cnt == 0 && s.size() % 2 == 1))
    puts("YES");
  else
    puts("NO");
}
