#include <bits/stdc++.h>
using namespace std;
long long Set(long long N, long long pos) { return N = N | (1 << pos); }
long long reset(long long N, long long pos) { return N = N & ~(1 << pos); }
bool check(long long N, long long pos) { return (bool)(N & (1 << pos)); }
void CI(long long &_x) { scanf("%d", &_x); }
void CO(long long &_x) { cout << _x; }
template <typename T>
void getarray(T a[], long long n) {
  for (long long i = 0; i < n; i++) cin >> a[i];
}
template <typename T>
void prLLIarray(T a[], long long n) {
  for (long long i = 0; i < n - 1; i++) cout << a[i] << " ";
  cout << a[n - 1] << endl;
}
const double EPS = 1e-9;
const long long INF = 0x7f7f7f7f;
long long dr8[8] = {1, -1, 0, 0, 1, -1, -1, 1};
long long dc8[8] = {0, 0, -1, 1, 1, 1, -1, -1};
long long dr4[4] = {0, 0, 1, -1};
long long dc4[4] = {-1, 1, 0, 0};
long long kn8r[8] = {1, 2, 2, 1, -1, -2, -2, -1};
long long kn8c[8] = {2, 1, -1, -2, -2, -1, 1, 2};
pair<long long, long long> ar[100005];
long long n, A, Cf, Cm, M;
void input() {
  cin >> n >> A >> Cf >> Cm >> M;
  for (long long i = 1; i <= n; i++) {
    cin >> ar[i].first;
    ar[i].second = i;
  }
}
long long prefix[100005];
long long cost_cal(long long val, long long inx) {
  long long low = 1, hi = inx;
  if (ar[inx].first <= val) {
    return (val * inx) - prefix[inx];
  }
  while (low < hi) {
    long long mid = (low + hi) / 2;
    if (ar[mid].first > val)
      hi = mid;
    else
      low = mid + 1;
  }
  hi--;
  return (val * hi) - prefix[hi];
}
long long fixed_min_val(long long val, long long inx) {
  long long low = ar[1].first;
  long long hi = A;
  long long cost = cost_cal(hi, inx);
  if (cost <= val) {
    return hi;
  }
  while (low < hi) {
    long long mid = (low + hi) / 2;
    cost = cost_cal(mid, inx);
    if (cost > val)
      hi = mid;
    else
      low = mid + 1;
  }
  return hi - 1;
}
long long res[100005];
void proc() {
  sort(ar + 1, ar + n + 1);
  for (long long i = 1; i <= n; i++) prefix[i] = ar[i].first;
  for (long long i = 1; i <= n; i++) prefix[i] += prefix[i - 1];
  long long need = 0;
  long long ans = 0;
  long long id1 = -1, min_val;
  for (long long i = n + 1; i >= 1; i--) {
    need = need + (A - ar[i].first);
    if (i == n + 1) need = 0;
    if (need > M) break;
    long long a = Cf * (n - i + 1);
    long long b = fixed_min_val(M - need, i - 1);
    long long m_v = b;
    b = b * Cm;
    if (ans <= (a + b)) {
      ans = a + b;
      id1 = i;
      min_val = m_v;
    }
  }
  for (long long i = id1; i <= n; i++) ar[i].first = A;
  for (long long i = 1; i <= n; i++)
    if (ar[i].first < min_val) ar[i].first = min_val;
  for (long long i = 1; i <= n; i++) res[ar[i].second] = ar[i].first;
  cout << ans << "\n";
  for (long long i = 1; i <= n; i++) cout << res[i] << " ";
  puts("");
}
int main() {
  input();
  proc();
}
