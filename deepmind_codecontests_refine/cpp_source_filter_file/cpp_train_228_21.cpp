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
void __print(const char *x) { cerr << '"' << x << '"'; }
void __print(const string &x) { cerr << '"' << x << '"'; }
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
vector<int> input(int n) {
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  return a;
}
vector<long long int> input_lli(int n) {
  vector<long long int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  return a;
}
void print(vector<int> arr) {
  for (int i = 0; i < arr.size(); ++i) cout << arr[i] << ' ';
  cout << endl;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> arr(26, 0);
    ;
    int last = m;
    int j = 0;
    vector<int> q(m);
    for (int i = 0; i < m; ++i) {
      cin >> q[i];
    }
    sort(q.begin(), q.end());
    ;
    for (int i = 0; i < n; ++i) {
      if (i < q[j]) {
        arr[s[i] - 'a'] += last;
      } else {
        while (i >= q[j]) {
          last -= 1;
          ++j;
        }
        arr[s[i] - 'a'] += last;
      }
      arr[s[i] - 'a'] += 1;
      ;
    }
    for (int i = 0; i < 26; ++i) {
      cout << arr[i] << ' ';
    }
    cout << '\n';
  }
  return 0;
}
