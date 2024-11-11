#include <bits/stdc++.h>
using namespace std;
int a[300500];
int p[2];
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    long long int x;
    cin >> x;
    a[i] = __builtin_popcountll(x);
  }
  long long int res = 0;
  p[0] = 1;
  int now = 0;
  for (int i = 0; i < n; i++) {
    now += a[i];
    now %= 2;
    res += p[now];
    ++p[now];
  }
  for (int i = 0; i < n; i++) {
    int now = 0;
    int mx = 0;
    for (int j = i; j < min(n, i + 70); j++) {
      now += a[j];
      mx = max(mx, a[j]);
      if (now % 2 == 0 && mx * 2 > now) --res;
    }
  }
  cout << res;
  return 0;
}
