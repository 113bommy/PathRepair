#include <bits/stdc++.h>
using namespace std;
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
ostream& operator<<(ostream& ost, const vector<T>& v) {
  ost << "{";
  for (long long i = 0; i < v.size(); i++) {
    if (i) ost << ",";
    ost << v[i];
  }
  ost << "}";
  return ost;
}
void solve() {
  long long N, K;
  cin >> N >> K;
  string S;
  cin >> S;
  string T;
  for (long long i = 0; i < (K - 1); i++) T += "()";
  T += string((N - T.size()) / 2, '(');
  T += string(N - T.size(), ')');
  vector<pair<long long, long long> > ans;
  for (long long i = 0; i < N; i++) {
    if (S[i] == T[i]) continue;
    long long j = i;
    while (S[j] != T[i]) j++;
    ans.emplace_back(i, j);
    reverse(S.begin() + i, S.begin() + j + 1);
  }
  cout << ans.size() << endl;
  for (auto& p : ans) cout << p.first + 1 << " " << p.second << endl;
}
signed main() {
  long long T;
  scanf("%lld", &T);
  while (T--) solve();
  return 0;
}
