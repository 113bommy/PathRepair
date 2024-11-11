#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e6 + 10;
int n, a[MAXN], b[MAXN], sum[MAXN];
long long x, ans;
int cnt() {
  int res = 0;
  while (x > 0) {
    res += x % 2;
    x /= 2;
  }
  return res;
}
long long calc(int l) {
  int maxx = a[l], res = 0;
  for (int i = l + 1; i < min(n, l + 65); i++) {
    maxx = max(maxx, a[l]);
    int h = sum[i];
    if (l - 1 >= 0) h -= sum[l - 1];
    if (h % 2 == 0 && maxx > h / 2) res++;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    a[i] = cnt();
  }
  b[0] = a[0] % 2;
  sum[0] = a[0];
  for (int i = 1; i < n; i++) {
    b[i] = (b[i - 1] + a[i]) % 2;
    sum[i] = sum[i - 1] + a[i];
  }
  int odd = 0, even = 0;
  b[n - 1] == 0 ? even++ : odd++;
  for (int i = n - 2; i >= 0; i--) {
    long long cur;
    if (i - 1 >= 0) {
      b[i - 1] == 0 ? cur = even : cur = odd;
    } else
      cur = even;
    cur -= calc(i);
    ans += cur;
    b[i] == 0 ? even++ : odd++;
  }
  cout << ans;
  return 0;
}
