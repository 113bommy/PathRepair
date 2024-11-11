#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int cnt = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'z') cnt++;
  }
  int len = s.size();
  len -= cnt * 4;
  len /= 3;
  for (int i = 0; i < cnt; i++) {
    printf("%d ", 1);
  }
  for (int i = 0; i < len; i++) {
    printf("%d ", 0);
  }
  return 0;
}
