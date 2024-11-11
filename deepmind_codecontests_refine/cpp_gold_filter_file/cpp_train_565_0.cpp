#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
int n, sumh[N], sumt[N], ans;
char s[N];
int main() {
  cin >> n;
  ans = 0x3f3f3f3f;
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++) {
    sumh[i] = sumh[i - 1];
    sumt[i] = sumt[i - 1];
    if (s[i] == 'H')
      sumh[i]++;
    else
      sumt[i]++;
  }
  for (int i = 1; i <= n - sumh[n] + 1; i++)
    ans = min(ans, sumt[i + sumh[n] - 1] - sumt[i - 1]);
  for (int i = 1; i <= n - sumt[n] + 1; i++)
    ans = min(ans, sumh[i + sumt[n] - 1] - sumh[i - 1]);
  printf("%d\n", ans);
  return 0;
}
