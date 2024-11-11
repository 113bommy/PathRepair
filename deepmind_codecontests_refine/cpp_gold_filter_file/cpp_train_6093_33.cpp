#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 200100;
long long a[maxn], b[maxn];
int main() {
  {
    srand(time(0));
    const string file = "";
    if (!file.empty()) {
      freopen((file + ".in").c_str(), "r", stdin);
      freopen((file + ".out").c_str(), "w", stdout);
    }
  }
  int n, k;
  scanf("%d%d", &n, &k);
  n++;
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
    b[i] = a[i];
  }
  for (int i = 0; i < n - 1; i++) {
    a[i + 1] += a[i] / 2;
    a[i] %= 2;
    if (a[i] == -1) {
      a[i] = 1;
      a[i + 1] += -1;
    }
  }
  if (a[n - 1] < 0) {
    for (int i = 0; i < n; i++) {
      b[i] = -b[i];
      a[i] = b[i];
    }
    for (int i = 0; i < n - 1; i++) {
      a[i + 1] += a[i] / 2;
      a[i] %= 2;
      if (a[i] == -1) {
        a[i] = 1;
        a[i + 1] += -1;
      }
    }
  }
  int st = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] != 0) {
      st = i;
      break;
    }
  }
  long long cnt = 0, q = 1, qq = 0;
  for (int i = st; cnt <= 2 * k && i < n; i++, q *= 2, qq++) {
    if (qq > 33 && a[i] != 0) {
      cnt = mod * 1ll * mod;
      break;
    }
    cnt += q * a[i];
  }
  long long ans = 0;
  while (((cnt) < 0 ? -(cnt) : (cnt)) <= 5ll * mod && st >= 0) {
    if (cnt == b[st] && st == n - 1) {
    } else
      ans += (((b[st] - cnt) < 0 ? -(b[st] - cnt) : (b[st] - cnt)) <= k);
    cnt *= 2;
    st--;
  }
  printf("%lld", max(ans, ans));
  return (0);
}
