#include <bits/stdc++.h>
using namespace std;
int a[300007];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  string s;
  cin >> s;
  int sum = 1;
  a[0] = 1;
  for (int i = (1); i <= (n - 1); ++i) {
    if (sum && s[i] == '.') a[i] = 1;
    sum += a[i];
    if (i >= k) sum -= a[i - k];
  }
  if (a[n - 1])
    puts("YES");
  else
    puts("NO");
  return 0;
}
