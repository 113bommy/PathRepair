#include <bits/stdc++.h>
using namespace std;
double PI = acos(-1);
int const N = 1e6 + 10, M = 1e7 + 1, oo = 1e9;
const int mod = oo + 7;
const long long OO = 3e18;
int n, aa[N], pr[M];
long long cnt[M];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 2; i * i < M; i++) {
    if (pr[i]) continue;
    pr[i] = i;
    for (int j = i; j < M; j += i) pr[j] = i;
  }
  for (int i = 2; i < M; i++)
    if (pr[i] == 0) pr[i] = i;
  cin >> n;
  for (int i = 0, a; i < n; i++) {
    cin >> a;
    cnt[a]++;
  }
  for (int i = M - 2; i > 0; i--) cnt[i] += cnt[i + 1];
  for (int i = M - 1; i > 0; i--) {
    if (cnt[i] == 0 || pr[i] == i) continue;
    int y = i;
    while (y > 1) {
      int r = pr[y], c = 0;
      while (y % r == 0) y /= r, c++;
      cnt[r] += c * 1LL * cnt[i];
    }
  }
  long long an = 1;
  for (int i = 2; i < M; i++) {
    if (pr[i] != i || cnt[i] == 0) continue;
    long long l = 1, r = OO, mid, res = 0;
    while (l <= r) {
      mid = (l + r) >> 1;
      long long op = mid, c = 0;
      while (op) {
        op /= i;
        c += op;
      }
      if (c >= cnt[i]) {
        res = mid;
        r = mid - 1;
      } else
        l = mid + 1;
    }
    an = max(an, res);
  }
  cout << an;
  return 0;
}
