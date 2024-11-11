#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream& dbg_print(ostream& out, const T& dbg_t) {
  out << "[";
  for (auto i : dbg_t) out << i << ", ";
  out << "]";
  return out;
}
template <typename T>
ostream& operator<<(ostream& out, const set<T>& dbg_t) {
  return dbg_print(out, dbg_t);
}
template <typename T>
ostream& operator<<(ostream& out, const vector<T>& dbg_t) {
  return dbg_print(out, dbg_t);
}
template <typename S, typename T>
ostream& operator<<(ostream& out, const pair<S, T>& rhs) {
  out << "(" << rhs.first << "," << rhs.second << ")";
  return out;
}
template <typename T>
void max_e(T& aaa, const T& bbb) {
  aaa = max(aaa, bbb);
}
template <typename T>
void min_e(T& aaa, const T& bbb) {
  aaa = min(aaa, bbb);
}
int n;
long long k;
vector<long long> total, taken;
long long delta(int i, long long x) { return total[i] - 3 * x * x + 3 * x - 1; }
long long threshold(int i, long long A) {
  long long b = 0;
  long long e = total[i];
  while (b < e) {
    long long s = (b + e + 1) / 2;
    if (delta(i, s) >= A)
      b = s;
    else
      e = s - 1;
  }
  return b;
}
long long common_threshold() {
  long long b = 0;
  for (int i = 0; i < int(n); ++i) min_e(b, delta(i, total[i]));
  long long e = 0;
  for (int i = 0; i < int(n); ++i) max_e(e, delta(i, 1));
  while (b < e) {
    long long s = (b + e + 1) / 2;
    long long x_sum = 0;
    for (int i = 0; i < int(n); ++i) x_sum += threshold(i, s);
    if (x_sum >= k)
      b = s;
    else
      e = s - 1;
  }
  return b;
}
void solve() {
  long long A = common_threshold();
  if (1)
    cout << "A"
         << " " << A << " " << endl;
  long long all_taken = 0;
  for (int i = 0; i < int(n); ++i) {
    taken[i] = threshold(i, A);
    all_taken += taken[i];
  }
  for (int i = 0; i < int(n); ++i)
    if (all_taken > k && delta(i, taken[i]) == A) {
      taken[i]--;
      all_taken--;
    }
  assert(all_taken == k);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  total.assign(n, 0);
  for (int i = 0; i < int(n); ++i) cin >> total[i];
  taken.assign(n, 0);
  solve();
  for (int i = 0; i < int(n); ++i) cout << taken[i] << " ";
  cout << endl;
  return 0;
}
