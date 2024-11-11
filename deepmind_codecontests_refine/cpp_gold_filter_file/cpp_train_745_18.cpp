#include <bits/stdc++.h>
const double eps = 1e-9;
const int oo = 1000000000;
const double E = 2.7182818284590452353602874713527;
const double pi = 3.1415926535897932384626433832795;
using namespace std;
long long d[3333];
int p[15], pos[3333], rec[15];
int main() {
  int n, k, pn, st = 0, en = 0, ans = 0;
  while (st <= en) {
    if (d[st] <= 100000000) {
      d[++en] = d[st] * 10 + 4;
      d[++en] = d[st] * 10 + 7;
    }
    st++;
  }
  p[0] = 1;
  for (int i = 1; i <= 12; i++) p[i] = p[i - 1] * i;
  cin >> n >> k;
  if (n <= 12 && p[n] < k) {
    cout << -1;
    goto end;
  }
  pn = ((n) < (13) ? (n) : (13));
  for (int i = pn; i; i--) {
    int tmp = 1;
    while (rec[tmp]) tmp++;
    while (k > p[i - 1]) {
      k -= p[i - 1];
      tmp++;
      while (rec[tmp]) tmp++;
    }
    rec[tmp] = i;
  }
  while (d[en] > n) en--;
  for (int i = 1; i <= en; i++) {
    if (d[i] <= n - pn)
      pos[i] = d[i];
    else
      pos[i] = n - rec[d[i] - (n - pn)] + 1;
    for (int j = 1; j <= en; j++)
      if (pos[i] == d[j]) {
        ans++;
        break;
      }
  }
  cout << ans;
end:
  return 0;
}
