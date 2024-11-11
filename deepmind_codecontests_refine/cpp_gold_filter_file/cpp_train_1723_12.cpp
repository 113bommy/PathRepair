#include <bits/stdc++.h>
using namespace std;
const int N = 3e6 + 7;
long long mul[N];
int cnt[N];
long long pref[N];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  fill(cnt, cnt + N, 0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cnt[x]++;
  }
  fill(mul, mul + N, 0);
  for (int i = 1; i < N; i++) {
    for (int j = i; j < N; j += i) {
      int other = j / i;
      if (i == other) {
        mul[j] += (long long)cnt[i] * (cnt[i] - 1);
      } else {
        if (i < other) {
          mul[j] += 2 * (long long)cnt[i] * cnt[other];
        }
      }
    }
  }
  pref[0] = 0;
  for (int i = 1; i < N; i++) {
    pref[i] = pref[i - 1] + mul[i];
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int p;
    cin >> p;
    cout << (long long)(n) * (n - 1) - pref[p - 1] << '\n';
  }
}
