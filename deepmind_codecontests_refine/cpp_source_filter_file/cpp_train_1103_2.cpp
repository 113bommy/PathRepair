#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 30;
const long long INF = 1ll << 60;
const double pi = acos(-1);
const double eps = 1e-9;
const long long mod = 1e9 + 7;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
long long n, k, a[10];
string s;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> k >> s;
  n = s.size();
  for (int i = 0; i < n; i++) a[s[i] - '0']++;
  long long t = 0;
  for (int i = 0; i < 10; i++) k -= a[i] * (i + 1);
  if (k <= 0) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 0; i < 10; i++) {
    long long S = (8 - i) * a[i];
    if (S >= k) {
      cout << t + (k + 7 - i) / (8 - i) << endl;
      break;
    } else
      k -= S, t += a[i];
  }
}
