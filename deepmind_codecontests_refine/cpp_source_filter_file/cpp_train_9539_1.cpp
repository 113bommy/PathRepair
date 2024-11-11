#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
const int mod = 1e9 + 7;
const long long inf = 1e15;
const int maxn = 3e5 + 10;
template <class X>
void print(X a) {
  cout << a << endl;
  exit(0);
}
void makeTree(int i, int j, int sidx, long long a[], long long stree[]) {
  if (i == j) {
    stree[sidx] = a[i];
    return;
  }
  int mid = (i + j) >> 1;
  makeTree(i, mid, sidx * 2, a, stree);
  makeTree(mid + 1, j, sidx * 2 + 1, a, stree);
  stree[sidx] = min(stree[sidx * 2], stree[sidx * 2 + 1]);
}
long long query(int i, int j, int sidx, long long stree[], int ql, int qr) {
  if (i > qr or j < ql) return inf;
  if (i >= ql and j <= qr) return stree[sidx];
  int mid = (i + j) / 2;
  return min(query(i, mid, sidx * 2, stree, ql, qr),
             query(mid + 1, j, sidx * 2 + 1, stree, ql, qr));
}
void update(int i, int j, int sidx, long long stree[], int idx, long long val) {
  if (idx > j or idx < i) return;
  if (i == j) {
    stree[sidx] = val;
    return;
  }
  int mid = (i + j) / 2;
  update(i, mid, sidx * 2, stree, idx, val);
  update(mid + 1, j, sidx * 2 + 1, stree, idx, val);
  stree[sidx] = min(stree[sidx * 2], stree[sidx * 2 + 1]);
}
int n, a, b, c, d, start, len;
pair<long long, long long> A[maxn];
long long pfx[maxn];
long long stree[maxn * 4];
int last = 0;
bool perform(int idx, long long tim, long long curr_rating) {
  int end_time = tim + len;
  int lo = 1, hi = n, mid, ans;
  while (lo <= hi) {
    mid = (lo + hi) >> 1;
    if (A[mid].second < end_time) {
      ans = mid;
      lo = mid + 1;
    } else
      hi = mid - 1;
  }
  int j = ans;
  long long mn = query(1, n, 1, stree, idx + 1, j);
  mn -= pfx[idx];
  long long x = mn;
  if (curr_rating + x >= 0) return true;
  return false;
}
int main() {
  time_t t1, t2;
  t1 = clock();
  ios_base::sync_with_stdio(0);
  cin >> n >> a >> b >> c >> d >> start >> len;
  pfx[0] = 0;
  for (int i = 1; i <= n; i++) cin >> A[i].first >> A[i].second;
  for (int i = 1; i <= n; i++) {
    if (A[i].second == 1)
      pfx[i] = pfx[i - 1] + c;
    else
      pfx[i] = pfx[i - 1] - d;
  }
  makeTree(1, n, 1, pfx, stree);
  if (perform(0, 0, start)) {
    cout << 0 << endl;
    return 0;
  }
  long long curr = start;
  for (int i = 1; i <= n; i++) {
    if (perform(i - 1, A[i].first, curr)) {
      cout << A[i].first << endl;
      return 0;
    }
    if (A[i].second == 1)
      curr += a;
    else
      curr -= b;
    if (curr < 0) break;
    if (perform(i, A[i].first + 1, curr)) {
      cout << A[i].first + 1 << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  t2 = clock();
  cerr << "time taken: " << t2 - t1 << endl;
  return 0;
}
