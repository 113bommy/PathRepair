#include <bits/stdc++.h>
using namespace std;
using vint = vector<long long>;
using pint = pair<long long, long long>;
using vpint = vector<pint>;
template <typename A, typename B>
inline void chmin(A& a, B b) {
  if (a > b) a = b;
}
template <typename A, typename B>
inline void chmax(A& a, B b) {
  if (a < b) a = b;
}
template <class A, class B>
ostream& operator<<(ostream& ost, const pair<A, B>& p) {
  ost << "{" << p.first << "," << p.second << "}";
  return ost;
}
template <class T>
ostream& operator<<(ostream& ost, const vector<T>& A) {
  ost << "{";
  for (long long i = 0; i < A.size(); i++) {
    if (i) ost << ",";
    ost << A[i];
  }
  ost << "}";
  return ost;
}
long long ans[1111][1111];
long long A[1111];
void solve(long long l, long long r) {
  long long n = r - l;
  if (n == 0) return;
  if (A[r - 1] < n) {
    solve(l, r - 1);
    ans[n][r - 1] = 1;
    for (long long i = 0; i < A[r - 1] - 1; i--) ans[i][r - 1] = 1;
    return;
  }
  if (A[l] == 1) {
    ans[n][l] = 1;
    for (long long i = l + 1; i < r; i++)
      if (A[i] == n) {
        ans[n][i] = 1;
        A[i]--;
      }
    solve(l + 1, r);
    return;
  }
  for (long long i = l; i < r; i++) {
    ans[n][i] = 1;
    A[i]--;
  }
  solve(l + 1, r);
  for (long long i = 0; i < A[l]; i++) ans[i][l] = 1;
}
signed main() {
  long long N;
  scanf("%lld", &N);
  for (long long i = 0; i < (N); i++) scanf("%lld", &A[i]);
  vint ord(N);
  iota((ord).begin(), (ord).end(), 0);
  sort((ord).begin(), (ord).end(),
       [&](long long a, long long b) { return A[a] < A[b]; });
  sort(A, A + N);
  solve(0, N);
  vector<string> vec;
  for (long long i = 0; i < (N + 1); i++) {
    string s(N, '0');
    for (long long j = 0; j < (N); j++) s[ord[j]] = ans[i][j] + '0';
    if (count((s).begin(), (s).end(), '0') == N) continue;
    vec.push_back(s);
  }
  cout << vec.size() << endl;
  for (auto& s : vec) cout << s << endl;
}
