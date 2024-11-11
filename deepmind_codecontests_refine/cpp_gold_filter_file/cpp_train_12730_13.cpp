#include <bits/stdc++.h>
using namespace std;
vector<string> split(const string& s, char c) {
  vector<string> v;
  stringstream second(s);
  string x;
  while (getline(second, x, c)) v.emplace_back(x);
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
inline void __evars_out_var(T* val) {
  cerr << arrStr(val, 10);
}
template <typename T>
inline void __evars_out_var(T val) {
  cerr << val;
}
inline void __evars(vector<string>::iterator it) { cerr << '\n'; }
template <typename T, typename... Args>
inline void __evars(vector<string>::iterator it, T a, Args... args) {
  cerr << it->substr((*it)[0] == ' ', it->length()) << "=";
  __evars_out_var(a);
  cerr << "; ";
  __evars(++it, args...);
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long inf = 1e9 + 7;
int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[8] = {0, 0, -1, 1, 2, -2, 2, -2};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cout << 1 << " ";
    }
    cout << '\n';
  }
}
