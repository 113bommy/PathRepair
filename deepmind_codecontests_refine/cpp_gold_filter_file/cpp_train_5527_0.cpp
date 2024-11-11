#include <bits/stdc++.h>
using namespace std;
const int maxi = 211111;
map<long long, int> mp, hoise;
long long a[maxi];
int n, m;
long long odds = 0, evens = 0;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  a[0] = 0;
  a[n + 1] = m;
  long long res = 0;
  for (int i = 1; i <= n + 1; i += 2) {
    res += (a[i] - a[i - 1]);
  }
  int cnt = 0;
  for (int i = 1; i <= n + 1 && cnt <= min(50, n + 1); i++, cnt++) {
    long long tmp = 0;
    if (i & 1) {
      if (a[i] - 1 <= 0) continue;
      int pos = a[i] - 1;
      tmp += abs(pos - a[i - 1]);
      for (int j = i - 2; j >= 0; j -= 2) {
        if (j - 1 < 0) break;
        tmp += abs(a[j] - a[j - 1]);
      }
      for (int j = i; j <= n + 1; j += 2) {
        if (j + 1 > n + 1) break;
        tmp += abs(a[j] - a[j + 1]);
      }
    } else {
      if (a[i - 1] + 1 >= a[i]) continue;
      int pos = a[i - 1] + 1;
      tmp += abs(a[i] - pos);
      for (int j = i - 1; j >= 0; j -= 2) {
        if (j - 1 < 0) break;
        tmp += abs(a[j] - a[j - 1]);
      }
      for (int j = i + 1; j <= n + 1; j += 2) {
        if (j + 1 > n + 1) break;
        tmp += abs(a[j] - a[j + 1]);
      }
    }
    res = max(res, tmp);
  }
  cout << res << endl;
  return 0;
}
