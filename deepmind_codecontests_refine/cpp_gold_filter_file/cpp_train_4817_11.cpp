#include <bits/stdc++.h>
using namespace std;
vector<string> split(const string &s, char c) {
  vector<string> v;
  stringstream ss(s);
  string x;
  while (getline(ss, x, c)) v.emplace_back(x);
  return move(v);
}
template <typename T, typename... Args>
inline string arrStr(T arr, int n) {
  stringstream s;
  s << "[";
  for (int i = 0; i < n - 1; i++) s << arr[i] << ",";
  s << arr[n - 1] << "]";
  return s.str();
}
inline void __evars_begin(int line) { cerr << "#" << line << ": "; }
template <typename T>
inline void __evars_out_var(vector<T> val) {
  cerr << arrStr(val, val.size());
}
template <typename T>
inline void __evars_out_var(T *val) {
  cerr << arrStr(val, 10);
}
template <typename T>
inline void __evars_out_var(T val) {
  cerr << val;
}
inline void __evars(vector<string>::iterator it) { cerr << endl; }
template <typename T, typename... Args>
inline void __evars(vector<string>::iterator it, T a, Args... args) {
  cerr << it->substr((*it)[0] == ' ', it->length()) << "=";
  __evars_out_var(a);
  cerr << "; ";
  __evars(++it, args...);
}
int r, c, n, k, m;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (unsigned int c = 0; c < a.size(); cin >> a[c++])
    ;
  sort(a.begin(), a.end());
  int sum = 0;
  for (int c = 0; c < n - 1; ++c) {
    sum += a[c];
  };
  if (sum < a.back()) {
    cout << "T\n";
    return;
  } else {
    sum += a.back();
    if (sum % 2 == 0)
      cout << "HL\n";
    else
      cout << "T\n";
    return;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cerr.tie(NULL);
  ;
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
