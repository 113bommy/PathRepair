#include <bits/stdc++.h>
using namespace std;
int dx[8] = {-1, 1, 0, 0, 1, 1, -1, -1}, dy[8] = {0, 0, -1, 1, 1, -1, 1, -1};
char dc[4] = {'N', 'S', 'W', 'E'};
long long int a[500005], b[500005], su[500005];
int f(long long int st, long long int en, long long int val,
      long long int rem) {
  long long int l = st, h = en, mid, ans = st - 1;
  while (l <= h) {
    mid = (l + h) / 2;
    if (su[mid] - su[st - 1] - rem <= val) {
      ans = mid;
      l = mid + 1;
    } else
      h = mid - 1;
  }
  return ans;
}
int main() {
  long long int n, q, st, en, rem, ans;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= q; i++) cin >> b[i];
  su[1] = a[1];
  for (int i = 2; i <= n; i++) su[i] = su[i - 1] + a[i];
  st = 1;
  en = n;
  rem = 0;
  for (int i = 1; i <= q; i++) {
    ans = f(st, en, b[i], rem);
    cout << n - (ans == n ? 0 : ans) << endl;
    rem = b[i] - (su[ans] - su[st - 1]);
    st = ans + 1;
    if (ans == n) {
      st = 1;
      rem = 0;
    }
  }
}
