#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<long long> E;
void input();
void solve();
int main() {
  input();
  solve();
  return 0;
}
void input() {
  assert(scanf("%d", &n) == 1);
  assert(scanf("%d", &m) == 1);
  E.resize(n);
  do {
    for (typeof((E).begin()) i = (E).begin(); i != (E).end(); ++i) *i = n - 1;
  } while (false);
  for (int i = 0; i < m; i++) {
    int a, b;
    assert(scanf("%d", &a) == 1);
    assert(scanf("%d", &b) == 1);
    a--;
    b--;
    E[a]--;
    E[b]--;
  }
}
void solve() {
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    long long e = E[i];
    ans += e * (e - 1);
    ans -= e * (n - 1 - e);
    ans += (n - 1 - e) * (n - 2 - e);
  }
  cout << ans / 6 << endl;
}
