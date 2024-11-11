#include <bits/stdc++.h>
using namespace std;
template <typename Arg1, typename Arg2>
ostream& operator<<(ostream& out, const pair<Arg1, Arg2>& x) {
  return out << "(" << x.first << "," << x.second << ")";
}
template <typename Arg1>
ostream& operator<<(ostream& out, const vector<Arg1>& a) {
  out << "[";
  for (const auto& x : a) out << x << ",";
  return out << "]";
}
template <typename Arg1>
ostream& operator<<(ostream& out, const set<Arg1>& a) {
  out << "[";
  for (const auto& x : a) out << x << ",";
  return out << "]";
}
template <typename Arg1, typename Arg2>
ostream& operator<<(ostream& out, const map<Arg1, Arg2>& a) {
  out << "[";
  for (const auto& x : a) out << x << ",";
  return out << "]";
}
template <typename Arg1>
void __trace__(const string name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << " ] " << endl;
}
template <typename Arg1, typename... Args>
void __trace__(const string names, Arg1&& arg1, Args&&... args) {
  const string name = names.substr(0, names.find(','));
  cerr << name << " : " << arg1 << " | ";
  __trace__(names.substr(1 + (int)name.size()), args...);
}
clock_t time_p = clock();
void time_taken() {
  time_p = clock() - time_p;
  cerr << "Time Taken : " << (float)(time_p) / CLOCKS_PER_SEC << "\n";
}
const long long mod = 1e9 + 7;
const long long INF = 1e18;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout.precision(12);
  cout << fixed;
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<int> cnt(m);
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n; i++) {
      if (a[i][j] == '1') cnt[j]++;
    }
  }
  for (int i = 0; i < n; i++) {
    bool ok = 1;
    for (int j = 0; j < m; j++) {
      if (a[i][j]) ok &= (cnt[j] >= 2);
    }
    if (ok) {
      cout << "YES" << '\n';
      return 0;
    }
  }
  cout << "NO" << '\n';
  return 0;
  time_taken();
  return 0;
}
