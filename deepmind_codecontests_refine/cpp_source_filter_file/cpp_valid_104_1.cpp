#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char* x) { cerr << '\"' << x << '\"'; }
void __print(const string& x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V>& x) {
  cerr << '{';
  __print(x.first);
  cerr << ", ";
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T& x) {
  int first = 0;
  cerr << '{';
  for (auto& i : x) cerr << (first++ ? ", " : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001;
void solve() {
  int N;
  cin >> N;
  int A[N];
  for (int i = 0; i < (N); i++) cin >> A[i];
  int sum = 0;
  for (int i = 0; i < (N); i++) sum += A[i];
  if (sum % 2) {
    cout << "NO" << nl;
    return;
  }
  int cnt = 0;
  vector<int> ops;
  for (int i = 0; i < (N); i++) {
    cnt += A[i];
    if (A[i] == 0) {
      if (cnt % 2) {
        ops.push_back(i - 1);
        int X = 0;
        for (int j = 0; j < (3); j++) X ^= A[i - 1 + j];
        for (int j = 0; j < (3); j++) A[i - 1 + j] = X;
      }
      if (A[i] == 0) {
        cnt = 0;
      } else
        cnt++;
    }
  }
  sum = 0;
  for (int i = 0; i < (N); i++) sum += A[i];
  if (sum == N) {
    cout << "NO" << nl;
    return;
  }
  int fz = 0;
  for (int i = (N)-1; i >= 0; i--)
    if (A[i] == 0) fz = i;
  while (fz > 0) {
    ops.push_back(fz - 2);
    A[fz - 2] = 0;
    A[fz - 1] = 0;
    A[fz] = 0;
    fz -= 2;
  }
  for (int i = 0; i < (N); i++) {
    if (A[i] == 0 && A[i + 1] == 1) {
      ops.push_back(i);
      A[i] = 0;
      A[i + 1] = 0;
      A[i + 2] = 0;
    }
  }
  cout << "YES" << nl;
  cout << (int)(ops).size() << nl;
  for (auto& a : ops) {
    cout << a + 1 << " ";
  }
  cout << nl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
