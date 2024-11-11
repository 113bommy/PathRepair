#include <bits/stdc++.h>
using namespace std;
const int N = 1050000;
int f[N], size[N], n;
long long tmp1[N], tmp2[N], tmp[30], s[N], w[30], sl[N], sr[N];
void solve(int l, int r, int &n, long long s[]) {
  n = 1;
  s[1] = 0;
  for (int i = l; i <= r; i++) {
    for (int j = 1; j <= n; j++)
      tmp1[j] = s[j] + tmp[i], tmp2[j] = s[j] - tmp[i];
    for (int p = 1, q = 1, k = 1; p <= n || q <= n; ++k)
      if (p > n || (q <= n && tmp2[q] < tmp1[p]))
        s[k] = tmp2[q++];
      else
        s[k] = tmp1[p++];
    n <<= 1;
  }
}
int judge(int S) {
  if (size[S] == 1) return 0;
  int tn = 0;
  long long sum = 0;
  for (int i = 0; i < n; i++)
    if (S >> i & 1) tmp[++tn] = w[i + 1], sum += w[i + 1];
  if ((sum & 1) != ((size[S] - 1) & 1)) return 0;
  int ln = 0, rn = 0;
  int mid = tn >> 1;
  solve(1, mid, ln, sl), solve(mid + 1, tn, rn, sr);
  int j = rn;
  int siz = size[S] - 1;
  int pd = 1;
  if (sum <= siz && sum >= -siz) pd += 2;
  for (int i = 1; i <= ln && pd; i++) {
    while (j - 1 >= 1 && sl[i] + sr[j - 1] >= -siz) --j;
    while (j <= rn && sl[i] + sr[j] >= -siz && sl[i] + sr[j] <= siz && pd)
      --pd, j++;
  }
  return !pd;
}
int main() {
  scanf("%d", &n);
  int tn = 0;
  for (int i = 1; i <= n; i++) {
    long long x;
    scanf("%lld", &x);
    if (x) w[++tn] = x;
  }
  n = tn;
  int U = (1 << n) - 1;
  for (int S = 1; S <= U; S++) {
    size[S] = size[S >> 1] + (S & 1);
    if (!f[S] && judge(S)) {
      f[S] = 1;
      for (int T = U ^ S; T; T = (T - 1) & (U ^ S))
        f[S | T] = max(f[S | T], f[T] + 1);
    }
  }
  int ans = tn;
  for (int S = 0; S <= U; S++) ans = min(ans, n - f[S]);
  cout << ans << endl;
}
