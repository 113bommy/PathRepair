#include <bits/stdc++.h>
using namespace std;
const long long int INF = 1000000005;
int main() {
  string s;
  cin >> s;
  if (s.length() < 3) {
    printf("No");
    return 0;
  }
  for (int i = 0; i < s.length() - 2; i++) {
    if (s[i] != s[i + 1] && s[i + 1] != s[i + 2] && s[i + 2] != s[i] &&
        s[i] != '.' && s[i + 1] != '.' && s[i + 2] != '.') {
      printf("Yes");
      return 0;
    }
  }
  printf("No");
  return 0;
}
