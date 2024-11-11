#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005;
int one[maxn], two[maxn], store[maxn];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &store[i]);
  for (int i = 1; i <= n; ++i) one[i] = one[i - 1] + (store[i] == 1);
  for (int i = n; i >= 1; --i) two[i] = two[i + 1] + (store[i] == 2);
  int ans = 0;
  for (int pos = 1; pos <= n; ++pos) {
    int num1 = 0, num2 = 0;
    for (int l = pos; l >= 1; --l)
      num1 = max(num1, one[l - 1] + two[l] - two[pos + 1]);
    for (int r = pos; r <= n; ++r)
      num2 = max(num2, two[r + 1] + one[r] - one[pos]);
    ans = max(ans, num1 + num2);
  }
  printf("%d\n", ans);
  return 0;
}
