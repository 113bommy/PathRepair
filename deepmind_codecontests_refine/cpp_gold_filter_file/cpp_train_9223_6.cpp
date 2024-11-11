#include <bits/stdc++.h>
using namespace std;
bool fun(int a, int b) {
  long long s = (long long)a * b, t, mid;
  long long l = 0, r = 1000000;
  while (l <= r) {
    mid = (l + r) / 2;
    t = mid * mid * mid;
    if (t == s) break;
    if (t > s)
      r = mid - 1;
    else
      l = mid + 1;
  }
  if (t != s) return 0;
  if (a % mid != 0 || b % mid != 0) return 0;
  return 1;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    if (fun(a, b))
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
