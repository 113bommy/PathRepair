#include <bits/stdc++.h>
using namespace std;
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
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
const long long int MOD = 1e9 + 7;
const long long int INF = 1e18;
const long long int maxn = 2e6 + 4;
void solve() {
  int n;
  cin >> n;
  vector<int> v(maxn);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    v[a]++;
  }
  int lst = 0;
  int ans = 0;
  for (int i = 0; i < maxn; i++) {
    ans += ((v[i] + lst) % 2 > 0);
    lst = (v[i] + lst) / 2;
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  cerr << endl
       << "[ Time : " << (float)clock() / CLOCKS_PER_SEC << " secs ]" << endl;
}
