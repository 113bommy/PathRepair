#include <bits/stdc++.h>
using namespace std;
string to_string(char c) { return string(1, c); }
string to_string(bool b) { return b ? "true" : "false"; }
string to_string(const char* s) { return (string)s; }
string to_string(string s) { return s; }
template <class A>
string to_string(complex<A> c) {
  stringstream ss;
  ss << c;
  return ss.str();
}
string to_string(vector<bool> v) {
  string res = "{";
  for (int i = 0; i < (int)(v).size(); ++i) res += char('0' + v[i]);
  res += "}";
  return res;
}
template <size_t SZ>
string to_string(bitset<SZ> b) {
  string res = "";
  for (int i = 0; i < SZ; ++i) res += char('0' + b[i]);
  return res;
}
template <class A, class B>
string to_string(pair<A, B> p);
template <class T>
string to_string(T v) {
  bool fst = 1;
  string res = "{";
  for (const auto& x : v) {
    if (!fst) res += ", ";
    fst = 0;
    res += to_string(x);
  }
  res += "}";
  return res;
}
template <class A, class B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
void DBG() { cerr << "]" << '\n'; }
template <class H, class... T>
void DBG(H h, T... t) {
  cerr << to_string(h);
  if (sizeof...(t)) cerr << ", ";
  DBG(t...);
}
void EDBG(string names) { names = names; }
template <class H, class... T>
void EDBG(string names, H h, T... t) {
  auto pos = names.find(',');
  auto first_name = names.substr(0, pos);
  auto rest = names.substr(pos + 1);
  while (rest.front() == ' ') {
    rest = rest.substr(1);
  }
  cerr << "[" << first_name << "]: [" << to_string(h) << "]"
       << "\n";
  EDBG(rest, t...);
}
vector<vector<bool> > ma;
long long n, m;
void solve() {
  cin >> n >> m;
  ma.assign(n, vector<bool>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char x;
      cin >> x;
      if (x == '1')
        ma[i][j] = 1;
      else
        ma[i][j] = 0;
    }
  }
  int k = 0;
  vector<vector<int> > ans;
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < m - 1; j++) {
      if (ma[i][j]) {
        ma[i][j] = 0;
        k += 3;
        vector<int> curr = {i, j, i + 1, j, i + 1, j + 1};
        ans.push_back(curr);
        vector<int> curr1 = {i, j, i, j + 1, i + 1, j + 1};
        ans.push_back(curr1);
        vector<int> curr2 = {i, j, i + 1, j, i, j + 1};
        ans.push_back(curr2);
      }
    }
  }
  if (ma[n - 1][m - 1] == 1) {
    k += 3;
    int i = n - 2, j = m - 2;
    vector<int> curr = {i, j, i, j + 1, i + 1, j + 1};
    ans.push_back(curr);
    vector<int> curr1 = {i, j + 1, i + 1, j, i + 1, j + 1};
    ans.push_back(curr1);
    vector<int> curr2 = {i, j, i + 1, j, i + 1, j + 1};
    ans.push_back(curr2);
  }
  for (int i = (int)0; i <= (int)n - 2; i++) {
    if (ma[i][m - 1] == 1) {
      k += 3;
      int j = m - 2;
      vector<int> curr = {i, j + 1, i + 1, j, i + 1, j + 1};
      ans.push_back(curr);
      vector<int> curr1 = {i, j, i + 1, j, i, j + 1};
      ans.push_back(curr1);
      vector<int> curr2 = {i, j, i, j + 1, i + 1, j + 1};
      ans.push_back(curr2);
    }
  }
  for (int j = 0; j < m - 1; j++) {
    if (ma[n - 1][j] == 1) {
      k += 3;
      int i = n - 2;
      vector<int> curr = {i, j, i + 1, j, i, j + 1};
      ans.push_back(curr);
      vector<int> curr1 = {i + 1, j, i + 1, j + 1, i, j + 1};
      ans.push_back(curr1);
      vector<int> curr2 = {i, j, i + 1, j + 1, i + 1, j};
      ans.push_back(curr2);
    }
  }
  cout << k << '\n';
  for (auto i : ans) {
    for (int j : i) {
      cout << j << " ";
    }
    cout << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
