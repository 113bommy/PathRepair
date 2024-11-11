#include <bits/stdc++.h>
using namespace std;
const int LIMIT = 1e6 + 7;
const int INF = 2e9 + 7;
long long n, r, p;
string s;
int main() {
  scanf("%lld", &n);
  cin >> s;
  if (n & 1) {
    printf("-1");
    return EXIT_SUCCESS;
  }
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      p++;
    } else {
      p--;
    }
    if (p < 0 || (!p && s[i] == '(')) {
      r++;
    }
  }
  printf("%lld", r);
  return EXIT_SUCCESS;
}
