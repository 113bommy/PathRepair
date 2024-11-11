#include <bits/stdc++.h>
using namespace std;
void read(int& x) { scanf("%d", &x); }
void read(long long& x) { scanf("%lld", &x); }
template <typename T, typename... Args>
void read(T& a, Args&... b) {
  read(a);
  read(b...);
}
vector<int> q[18], an[18];
void SU(vector<int>& v) {
  sort((v).begin(), (v).end());
  v.erase(unique((v).begin(), (v).end()), v.end());
}
void solve(int T) {
  an[T].clear();
  if (T == 17) {
    for (int t : q[T]) {
      if (t) an[T].push_back(-t);
    }
    SU(an[T]);
    return;
  }
  if (q[T].empty()) return;
  bool le = 0;
  for (int first : q[T])
    if (1 & (first >> T)) {
      le = 1;
      break;
    }
  if (!le) {
    q[T + 1] = q[T];
    solve(T + 1);
    an[T] = an[T + 1];
    return;
  }
  for (int df = -1; df <= 1; df += 2) {
    q[T + 1].clear();
    for (int first : q[T]) {
      if (1 & (first >> T)) first -= df * (1 << T);
      if (first) q[T + 1].push_back(first);
    }
    SU(q[T + 1]);
    solve(T + 1);
    an[T + 1].push_back(df * (1 << T));
    if (df == -1 || an[T].size() > an[T + 1].size()) an[T] = an[T + 1];
  }
}
int main() {
  int n;
  read(n);
  for (int i = 0; i <= 17; ++i) q[i].reserve(100000), an[i].reserve(100000);
  for (int first, i = 0; i < n; ++i) read(first), q[0].push_back(first);
  solve(0);
  printf("%d\n", int(an[0].size()));
  for (int first : an[0]) printf("%d ", first);
  return 0;
}
