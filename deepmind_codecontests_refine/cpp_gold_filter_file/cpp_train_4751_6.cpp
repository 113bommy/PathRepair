#include <bits/stdc++.h>
using namespace std;
struct pair_hash {
  template <class T1, class T2>
  std::size_t operator()(const std::pair<T1, T2>& pair) const {
    return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
  }
};
const long double EPS = 1e-6;
const long long MOD = 998244353;
const long long INF = 1e18;
const long double pi = 2 * acos(0.0);
long long n, m, k, p, q, t, sum = 0, cnt = 0;
long long mx = -INF;
long long mn = INF;
bool flag = 0;
vector<long long> v;
string s = "", s1, s2;
void bad_solve() {}
char tim[(long long)1e6 + 2] = {0};
void solve() {
  cin >> n >> m >> k;
  for (long long(i) = 0; (i) < (n); ++(i)) {
    cin >> p;
    tim[p] = 1;
  }
  long long l = 0;
  long long r = 0;
  stack<long long> st;
  while (r < m) {
    if (tim[r]) st.push(r);
    cnt += tim[r++];
  }
  --r;
  while (r < 1e6 + 1) {
    while (cnt >= k) {
      while (!st.empty() && st.top() < l) st.pop();
      tim[st.top()] = 0;
      st.pop();
      --cnt;
      ++sum;
    }
    if (tim[r + 1]) {
      st.push(r + 1);
      ++cnt;
    }
    if (tim[l]) --cnt;
    ++l;
    ++r;
  }
  cout << sum;
}
int main() {
  cout.precision(20);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
