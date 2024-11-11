#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  getchar();
  string s, t;
  getline(cin, s);
  getline(cin, t);
  long long cases = 1;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    cases = cases * 2;
    if (s[i] == 'b') cases--;
    if (t[i] == 'a') cases--;
    if (cases > k) {
      ans += k;
    } else {
      ans += cases;
    }
  }
  printf("%lld\n", ans);
}
