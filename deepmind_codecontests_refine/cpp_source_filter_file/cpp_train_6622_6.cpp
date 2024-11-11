#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
long long int n, k;
long long int a[maxn];
long long int b[maxn];
long long int s[maxn];
int ans[maxn], top;
int main() {
  long long int sum = 0;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) cin >> a[i], sum += a[i], b[i] = a[i];
  if (sum < k) {
    cout << -1 << endl;
  } else if (sum > k) {
    sort(b, b + n);
    s[0] = b[0];
    for (int i = 1; i < n; ++i) s[i] = b[i] + s[i - 1];
    for (int i = 0; i < n; ++i) {
      if (i > 0 && b[i] == b[i - 1]) continue;
      long long int cur = (i == 0 ? 0 : s[i - 1]) + b[i] * (n - i);
      if (cur > k) {
        long long int rem = (k - ((i == 0 ? 0 : s[i - 1]) +
                                  (i == 0 ? 0 : b[i - 1]) * (n - i))) %
                            (n - i);
        bool first = false;
        int st = 0, cnt = 0;
        for (int j = 0; j < n; ++j) {
          if (a[j] >= b[i]) {
            ++cnt;
            long long int cur2 = (i == 0 ? 0 : s[i - 1]) + a[j] * cnt +
                                 (a[j] - 1) * (n - i - cnt);
            if (cur2 == k)
              first = true, --rem;
            else if (cur2 > k) {
              if (first) first = false, st = top;
              ans[top++] = j + 1;
            } else
              --rem;
          }
        }
        st = (st + rem) % top;
        for (int j = st; j < top; ++j) cout << ans[j] << ' ';
        for (int j = 0; j < st; ++j) cout << ans[j] << ' ';
        cout << endl;
        break;
      }
    }
  }
  return 0;
}
