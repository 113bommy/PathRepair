#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
int cnt[(int)1e6 + 7];
int main() {
  long long n;
  scanf("%I64d", &n);
  long long cnt = 0;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%I64d", &x);
    if (x) {
      cnt++;
    } else {
      ans += cnt;
    }
  }
  printf("%I64d", ans);
  return 0;
}
