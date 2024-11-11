#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const long long INF = 1010000007;
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
string gh = "here";
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> a(n), t(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  n++;
  a.push_back(INF);
  t.push_back(0);
  vector<int> order(n);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int p, int q) { return a[p] < a[q]; });
  int last = 0;
  long long sum = 0;
  unsigned long long ans = 0;
  multiset<int> ms;
  for (int i = 0; i < n; i++) {
    int j = order[i];
    while (a[j] > last && !ms.empty()) {
      last++;
      auto it = prev(ms.end());
      sum -= *(it);
      ans += sum;
      ms.erase(it);
    }
    last = a[j];
    ms.insert(t[j]);
    sum += t[j];
  }
  cout << ans << '\n';
  return 0;
}
