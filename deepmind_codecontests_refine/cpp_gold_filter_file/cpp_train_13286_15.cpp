#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
const long long INF = 1LL << 62;
const int inf = 1 << 30;
template <class T>
bool chmax(T& a, const T& b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T& a, const T& b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& V) {
  int N = V.size();
  for (int i = 0; i < (N); i++) {
    os << V[i];
    if (i != N - 1) os << " ";
  }
  os << "\n";
  return os;
}
template <typename T, typename S>
ostream& operator<<(ostream& os, pair<T, S> const& P) {
  os << "(";
  os << P.first;
  os << " , ";
  os << P.second;
  os << ")";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, set<T>& S) {
  auto it = S.begin();
  while (it != S.end()) {
    os << *it;
    os << " ";
    it++;
  }
  os << "\n";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, deque<T>& q) {
  for (auto it = q.begin(); it < q.end(); it++) {
    os << *it;
    os << " ";
  }
  os << endl;
  return os;
}
template <typename T, typename S>
ostream& operator<<(ostream& os, map<T, S> const& M) {
  for (auto e : M) {
    os << e;
  }
  os << endl;
  return os;
}
vector<pair<int, int>> dxdy = {make_pair(0, 1), make_pair(1, 0),
                               make_pair(-1, 0), make_pair(0, -1)};
long long choose(long long n, long long k) {
  long long res = 1;
  for (int i = 0; i < (k); i++) {
    res *= n - i;
  }
  for (int i = 0; i < (k); i++) {
    res /= i + 1;
  }
  return res;
}
bool is_ok(vector<int>& A) {
  for (int i = 0; i < (A.size()); i++)
    if (A[i] == i) return false;
  return true;
}
long long solve(int N) {
  vector<int> A(N);
  for (int i = 0; i < (N); i++) A[i] = i;
  long long res = 0;
  while (next_permutation((A).begin(), (A).end())) {
    res += is_ok(A);
  }
  return res;
}
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int N, K;
  cin >> N >> K;
  long long ans = 0;
  for (int k = 1; k <= K; k++) {
    ans += choose(N, k) * solve(k);
  }
  cout << ans + 1 << endl;
}
