#include <bits/stdc++.h>
using namespace std;
const long double EPS = 10e-9;
const int INF = 1e9 + 5;
const long long INFLL = (long long)INF * (long long)INF;
const long long MOD = 1e9 + 7;
const long double PI = 3.14159265358979323846;
struct HASH {
  size_t operator()(const pair<int, int>& x) const {
    return hash<long long>()(((long long)x.first) ^
                             (((long long)x.second) << 32));
  }
};
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "[";
  for (int i = 0; i < (int)v.size(); ++i) {
    os << v[i];
    if (i != (int)v.size() - 1) os << ", ";
  }
  os << "]\n";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& v) {
  os << "{";
  for (const auto& it : v) {
    os << it;
    if (it != *v.rbegin()) os << ", ";
  }
  os << "}\n";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const unordered_set<T>& v) {
  os << "{";
  for (const auto& it : v) {
    os << it;
    if (it != *v.rbegin()) os << ", ";
  }
  os << "}\n";
  return os;
}
template <typename T, typename S>
ostream& operator<<(ostream& os, const map<T, S>& v) {
  os << "{";
  for (const auto& it : v) {
    os << it.first << " : " << it.second;
    if (it != *v.rbegin()) os << ", ";
  }
  os << "}\n";
  return os;
}
template <typename T, typename S>
ostream& operator<<(ostream& os, const unordered_map<T, S>& v) {
  os << "{";
  for (const auto& it : v) {
    os << it.first << " : " << it.second;
    if (it != *v.rbegin()) os << ", ";
  }
  os << "}\n";
  return os;
}
template <typename T, typename S>
ostream& operator<<(ostream& os, const pair<T, S>& v) {
  os << "(";
  os << v.first << ", " << v.second << ")";
  os << "\n";
  return os;
}
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
string construct(string& a, string& b) {
  int k = a.size();
  string res(k, '#');
  for (int i = 0; i < k; i++) {
    if (a[i] == b[i]) {
      res[i] = b[i];
    } else if (a[i] == 'S' && b[i] == 'E') {
      res[i] = 'T';
    } else if (a[i] == 'E' && b[i] == 'S') {
      res[i] = 'T';
    } else if (a[i] == 'E' && b[i] == 'T') {
      res[i] = 'S';
    } else if (a[i] == 'T' && b[i] == 'E') {
      res[i] = 'S';
    } else if (a[i] == 'S' && b[i] == 'T') {
      res[i] = 'E';
    } else if (a[i] == 'T' && b[i] == 'S') {
      res[i] = 'E';
    }
  }
  return res;
}
vector<long long> getFact(long long n, long long m) {
  vector<long long> fact(n + 1, 0);
  fact[0] = 1;
  for (int i = 1; i <= n; i++) {
    fact[i] = (fact[i - 1] * (long long)i) % m;
  }
  return fact;
}
void solve() {
  long long n, m;
  cin >> n >> m;
  vector<long long> fact = getFact(n, m);
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    ans += (fact[n - i] * fact[i]) % m * (n - i + 1) * (n - i + 1) % m;
    ans %= m;
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
