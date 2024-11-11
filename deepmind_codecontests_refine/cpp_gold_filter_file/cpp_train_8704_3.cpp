#include <bits/stdc++.h>
using namespace std;
int main() {
  int f = 0;
  string s, t;
  cin >> s;
  int l = s.size();
  for (int i = l - 1; i >= 0; i--) {
    if (f == 0) {
      if (s[i] == '0') continue;
    }
    if (s[i] != 0) {
      f = 1;
    }
    t += s[i];
  }
  string temp;
  temp = t;
  reverse(t.begin(), t.end());
  if (t == temp)
    printf("YES\n");
  else
    printf("NO\n");
}
