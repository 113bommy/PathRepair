#include <bits/stdc++.h>
using namespace std;
long long int a[500005], n, d;
long long int ans = 0;
void func(long long int st, long long int ed) {
  if (st + 1 == ed) return;
  if (a[st] == a[ed]) {
    ans = max(ans, (ed - st) / 2);
    for (int i = st; i <= ed; ++i) {
      a[i] = a[st];
    }
  } else {
    ans = max(ans, (ed - st) / 2);
    for (int i = st + 1; i <= (st + ed) / 2; ++i) {
      a[i] = a[st];
    }
    for (int i = (st + ed) / 2 + 1; i <= ed; ++i) {
      a[i] = a[ed];
    }
  }
}
int main(int argc, char const *argv[]) {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  long long int start, endx;
  a[0] = a[1];
  start = 1;
  endx = n;
  for (int i = start; i < endx; ++i) {
    if (a[i] == a[i + 1]) {
      func(start, i);
      start = i + 1;
    }
  }
  func(start, endx);
  printf("%lld\n", ans);
  for (int i = 1; i <= n; ++i) {
    cout << a[i] << " ";
  }
  return 0;
}
