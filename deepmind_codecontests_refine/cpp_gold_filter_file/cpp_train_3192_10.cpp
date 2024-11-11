#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 109;
int n;
char s[MAX_N];
int main() {
  cin.tie(NULL);
  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);
  cin >> n >> s;
  bool is = true;
  for (int i = 1; i < n; i++) {
    if (s[i] == '?') continue;
    if (s[i] == s[i - 1]) {
      is = false;
      break;
    }
  }
  if (!is) return !printf("No");
  for (int i = 0; i < n; i++) {
    if (s[i] == '?') {
      if (i - 1 >= 0 && i + 1 < n) {
        if (s[i - 1] == '?') return !printf("Yes");
        if (s[i + 1] == '?') return !printf("Yes");
        if (s[i - 1] == s[i + 1]) return !printf("Yes");
      } else
        return !printf("Yes");
    }
  }
  printf("No");
  return 0;
}
