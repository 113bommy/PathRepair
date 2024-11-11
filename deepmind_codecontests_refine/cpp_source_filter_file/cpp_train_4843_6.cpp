#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500100;
int main() {
  int n;
  long long A, cf, cm, M;
  cin >> n >> A >> cf >> cm >> M;
  pair<long long, long long> a[n + 1];
  long long cnt_max = 0;
  long long min_ = A;
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first;
    a[i].second = i;
    if (a[i].first == A) ++cnt_max;
    min_ = min(min_, a[i].first);
  }
  sort(a, a + n);
  long long ans = min_ * cm + cnt_max * cf;
  long long p[n];
  long long cp[n];
  for (long long i = 0; i < n; ++i) {
    cp[i] = a[i].first;
    if (i)
      p[i] = p[i - 1];
    else
      p[i] = 0;
    p[i] += a[i].first;
  }
  long long b[n];
  for (long long i = 0; i < n; ++i) b[i] = a[i].first * (i + 1) - p[i];
  int k = n - 1;
  for (; k != -1; --k)
    if (a[k].first != A) break;
  int m = k;
  ++m;
  a[m].first = A;
  long long bestM = M, besti = 0, bestm = m;
  for (long long i = cnt_max; i <= n; ++i, --m) {
    m = max(m, 0);
    M -= A - a[m].first;
    if (M < 0) break;
    a[m].first = A;
    long long B = M;
    k = upper_bound(b, b + m, B) - b;
    --k;
    if (k == -1) ++k;
    B -= b[k];
    long long cur_min;
    if (B > 0) {
      cur_min = a[k].first;
      cur_min += B / (k + 1);
      cur_min = min(cur_min, A);
    } else
      cur_min = a[0].first;
    if (ans < cur_min * cm + i * cf) {
      ans = cur_min * cm + i * cf;
      bestM = M;
      besti = i;
      bestm = m;
    }
  }
  cout << ans << endl;
  for (int i = n - besti - 1; i >= 0; --i) a[i].first = cp[i];
  long long B = bestM;
  m = bestm;
  k = upper_bound(b, b + m, B) - b;
  --k;
  if (k == -1) ++k;
  B -= b[k];
  long long cur_min;
  if (B > 0) {
    cur_min = a[k].first;
    cur_min += B / (k + 1);
    cur_min = min(cur_min, A);
  } else
    cur_min = a[0].first;
  for (int i = 0; i <= k; ++i) a[i].first = cur_min;
  for (int i = 0; i < n; ++i) swap(a[i].first, a[i].second);
  sort(a, a + n);
  for (int i = 0; i < n; ++i) cout << a[i].second << " ";
  printf("\n");
  return 0;
}
