#include <bits/stdc++.h>
using namespace std;
long long n, a[+100500], ans;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &a[i]);
  }
  for (int i = 2; i <= n; i++) {
    ans += abs(a[i] - a[i - 1]);
  }
  printf("%I64d", ans);
  return 0;
  ;
}
