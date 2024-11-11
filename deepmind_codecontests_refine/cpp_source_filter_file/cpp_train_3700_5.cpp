#include <bits/stdc++.h>
using namespace std;
int n;
long long pref[100007];
int main() {
  scanf("%d", &n);
  pref[0] = 0;
  for (int i = 1; i <= n; i++) {
    int a;
    scanf("%d", &a);
    pref[i] = pref[i - 1] + a;
  }
  sort(pref + 1, pref + n + 1);
  int licz = 1, mx = 1;
  for (int i = 2; i <= n; i++) {
    if (pref[i] == pref[i - 1])
      licz++;
    else
      licz = 0;
    mx = max(licz, mx);
  }
  printf("%d", n - mx);
  return 0;
}
