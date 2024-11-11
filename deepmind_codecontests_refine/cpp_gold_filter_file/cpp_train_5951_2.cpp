#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 2e6 + 10, inf = 1e18, mod = 1e9 + 7;
struct pair_hash {
  template <class T1, class T2>
  std::size_t operator()(const std::pair<T1, T2> &p) const {
    auto h1 = std::hash<T1>{}(p.first);
    auto h2 = std::hash<T2>{}(p.second);
    return h1 ^ h2;
  }
};
long long pw(long long te, long long tee) {
  if (tee == 0) return 1;
  long long res = pw(te, tee / 2);
  return (tee % 2 ? te * res * res : res * res);
}
long long n, a[MAXN];
void Read_input() {
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> a[i];
}
void Solve() {
  sort(a + 1, a + n + 1);
  bool flag = true;
  for (long long i = 2; i <= n; i++)
    if (a[i] != a[i - 1]) flag = false;
  if (flag) {
    cout << "Bob";
    exit(0);
  }
  long long cnt = 1;
  for (long long i = 2; i <= n; i++) {
    if (a[i] == a[i - 1])
      cnt++;
    else
      break;
  }
  if (cnt <= n / 2) {
    cout << "Alice";
    exit(0);
  }
  cout << "Bob";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  Read_input(), Solve();
  return 0;
}
