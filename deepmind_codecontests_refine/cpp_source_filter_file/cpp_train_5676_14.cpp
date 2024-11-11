#include <bits/stdc++.h>
using namespace std;
long long pre[100005], res[100005];
pair<long long, int> A[100005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m, i, j;
  long long a, s, cf, cm, mini = LLONG_MAX, maxi = 0, maxp, maxmini, x = 0;
  cin >> n >> a >> cf >> cm >> m;
  maxp = n;
  for (i = 0; i < n; i++) {
    cin >> A[i].first;
    A[i].second = i;
    if (A[i].first == a) maxi += cf;
    mini = min(mini, A[i].first);
  }
  maxmini = mini;
  maxi += mini * cm;
  sort(A, A + n);
  for (i = s = 0; i < n; i++) {
    s += A[i].first;
    pre[i] = A[i].first * (i + 1) - s;
  }
  for (i = n, s = 0; i >= 0; i--) {
    if (i < n) s += a - A[i].first;
    if (s > m) break;
    if (i) {
      j = upper_bound(pre, pre + i, m - s) - pre - 1;
      mini = min(a, A[j].first + (m - s - pre[j]) / (j + 1));
    } else
      mini = a, j = -1;
    if (mini * cm + (n - i) * cf > maxi) {
      maxi = mini * cm + (n - i) * cf;
      maxp = i;
      maxmini = mini;
      x = j;
    }
  }
  for (i = 0; i <= x; i++) res[A[i].second] = maxmini;
  for (i = x + 1; i < maxp; i++) res[A[i].second] = A[i].first;
  for (i = maxp; i < n; i++) res[A[i].second] = a;
  cout << maxi << '\n';
  for (i = 0; i < n; i++) cout << res[i] << " ";
  return 0;
}
