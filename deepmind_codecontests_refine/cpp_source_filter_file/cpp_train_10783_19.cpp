#include <bits/stdc++.h>
using namespace std;
void itval(istream_iterator<string> it) {}
template <typename T, typename... Args>
void itval(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << endl;
  itval(++it, args...);
}
template <typename T>
inline void print(T x) {
  cout << x << "\n";
}
template <typename T>
inline void printvec(T x) {
  for (auto a : x) cout << a << ' ';
  cout << '\n';
}
const long long int MOD = 1e9 + 7;
struct custom {
  bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) const {
    if (p1.first == p2.first) {
      return p1.second > p2.second;
    }
    return p1.first < p2.first;
  }
};
long long int get_pow(long long int x, long long int k) {
  if (k == 0) return 1ll;
  long long int y = get_pow(x, k / 2);
  y = (y * y) % MOD;
  if (k % 2) y = (y * x) % MOD;
  return y;
}
const int N = 1e6 + 10;
long long int bins(long long int val) {
  long long int u = 1e9, d = 1;
  while (d < u) {
    long long int mid = (u + d) / 2;
    long long int f = (mid * mid + mid) / 2;
    if (f < val) {
      d = mid + 1;
    } else {
      u = mid;
    }
  }
  return d;
}
void solve() {
  long long int n, m;
  cin >> n >> m;
  if (n <= m) {
    cout << n << "\n";
    return;
  }
  long long int days = m;
  long long int left = n;
  left = n - m;
  cout << days + bins(left) << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int test = 1;
  for (int tes = (int)0; tes < int(test); tes++) {
    solve();
  }
  return 0;
}
