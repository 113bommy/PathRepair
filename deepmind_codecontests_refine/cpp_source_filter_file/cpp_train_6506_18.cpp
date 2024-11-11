#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
char str[N + 1];
bool solve(int testNumber) {
  int n, m;
  if (scanf("%d %d", &n, &m) == EOF) return false;
  scanf("%s", str);
  int k = 0;
  for (int i = 1; i <= n; i++)
    if (str[i] != str[i - 1]) k++;
  long long ret = k * n * (m - 1);
  for (int i = 1; i < n; i++) {
    if (i > 1 && str[i] == str[i - 2]) continue;
    if (str[i] == str[i - 1]) continue;
    int s = i - 1, e = i;
    for (; e + 1 < n && str[e + 1] == str[e - 1]; e++)
      ;
    int l = e - s;
    ret -= 1LL * l * (l + 1) / 2;
  }
  printf("%lld\n", ret);
  return true;
}
int main() {
  for (int i = 1; solve(i); i++)
    ;
  return 0;
}
