#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 5e5 + 10;
char a[N];
int pre[N];
int main() {
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  cin >> (a + 1);
  long long ans = 0, sum = 0, now = 0;
  for (int i = 1; i <= n; i++) pre[i] = n + 1;
  for (int i = n; i; i--) {
    if (a[i] - '0')
      now++, sum += pre[now] - i;
    else
      while (now) pre[now] = i + now, now--;
    ans += sum;
  }
  cout << ans << '\n';
  return 0;
}
