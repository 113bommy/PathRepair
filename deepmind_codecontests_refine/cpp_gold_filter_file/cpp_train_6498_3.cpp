#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-9;
const int inf = LONG_MAX;
const long long inf64 = LLONG_MAX;
const long double pi = 3.1415926535897932384626433832795;
char a[10000];
int main() {
  gets(a);
  int n = strlen(a);
  int l = 0;
  int ans = 0;
  for (int i = 0; i < n - 3; i++)
    if (a[i] == 'b' && a[i + 1] == 'e' && a[i + 2] == 'a' && a[i + 3] == 'r') {
      ans += (i - l + 1) * (n - i - 3);
      l = i + 1;
    }
  printf("%d", ans);
  return 0;
}
