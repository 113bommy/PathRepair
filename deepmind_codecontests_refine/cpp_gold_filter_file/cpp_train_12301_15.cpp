#include <bits/stdc++.h>
const double pi = 4.0 * atan(1.0);
const double e = exp(1.0);
const int maxn = 3e5 + 8;
const long long mod = 1e9 + 7;
const unsigned long long base = 1e7 + 7;
using namespace std;
char s[maxn];
bool check(int l, int r) {
  for (int x = l; x <= r - 2; x++) {
    for (int k = 1; x + 2 * k <= r; k++) {
      if (s[x] == s[x + k] && s[x] == s[x + 2 * k]) {
        return 1;
      }
    }
  }
  return 0;
}
int main() {
  scanf("%s", s);
  long long ans = 0;
  int ls = strlen(s);
  for (int i = 0; s[i]; i++) {
    ans += max(0, ls - i - 10);
    for (int j = i + 2; j < i + 10 && s[j]; j++) {
      if (check(i, j)) {
        ans += min(i + 10, ls) - j;
        break;
      }
    }
  }
  cout << ans << endl;
}
