#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e5 + 10;
const long long INF = 1e18 + 10;
long long a[MAXN];
long long pdp[MAXN];
long long sdp[MAXN];
long long last_p[MAXN];
long long last_s[MAXN];
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(0);
  long long n, res = INF;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  pdp[0] = 0;
  last_p[0] = a[0];
  for (long long i = 1; i < n; i++) {
    if (a[i] > last_p[i - 1]) {
      pdp[i] = pdp[i - 1];
      last_p[i] = a[i];
    } else {
      pdp[i] = pdp[i - 1] + last_p[i - 1] - a[i] + 1;
      last_p[i] = last_p[i - 1] + 1;
    }
  }
  sdp[n - 1] = 0;
  last_s[n - 1] = a[n - 1];
  for (long long i = n - 2; i >= 0; i--) {
    if (a[i] > last_s[i + 1]) {
      sdp[i] = sdp[i + 1];
      last_s[i] = a[i];
    } else {
      sdp[i] = sdp[i + 1] + last_s[i + 1] - a[i] + 1;
      last_s[i] = last_s[i + 1] + 1;
    }
  }
  for (long long i = 0; i < n; i++) {
    res = min(res, (i == 0 ? 0 : pdp[i - 1]) + sdp[i + 1] +
                       (a[i] > max((i == 0 ? 0 : last_p[i - 1]), last_s[i + 1])
                            ? 0
                            : max((i == 0 ? 0 : last_p[i - 1]), last_s[i + 1]) -
                                  a[i] + 1));
  }
  cout << res;
}
