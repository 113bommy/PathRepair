#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int a = 0, b = 0, c = 0;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    if (i && s[i] < s[i - 1]) {
      printf("NO\n");
      return 0;
    }
    if (s[i] == 'a') {
      a++;
    }
    if (s[i] == 'b') {
      b++;
    }
    if (s[i] == 'c') {
      c++;
    }
  }
  if (a != 0 && b != 0 && (c == a || c == b)) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
  return 0;
}
