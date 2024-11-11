#include <bits/stdc++.h>
using namespace std;
char s[50005];
bool chk(int p) {
  int cnt = 0, ab[30] = {0};
  vector<char> can;
  for (int i = p; i < p + 26; i++) {
    if (s[i] == '?')
      cnt++;
    else
      ab[s[i] - 'A']++;
  }
  for (int i = 0; i < 26; i++) {
    if (ab[i] > 1) return false;
    if (ab[i] == 0) can.push_back(i + 'A');
  }
  if (can.size() == cnt) {
    for (int i = p; i < p + 26; i++)
      if (s[i] == '?') {
        s[i] = can.back();
        can.pop_back();
      }
    return true;
  }
  return false;
}
int main() {
  scanf("%s", s);
  int l = strlen(s);
  bool found = false;
  if (l < 26)
    printf("-1\n");
  else {
    for (int i = 0; i <= l - 26; i++) {
      if (chk(i)) {
        found = true;
        for (int j = 0; j < l; j++)
          if (s[j] == '?' and (j < i or j > i + 25)) s[j] = 'A';
        break;
      }
    }
    puts(found ? s : "-1");
  }
}
