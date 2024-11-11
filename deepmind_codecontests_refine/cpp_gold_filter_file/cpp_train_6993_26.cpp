#include <bits/stdc++.h>
using namespace std;
int mod = 1000000007;
const int inf = 2147483647;
const long long LL_INF = 1234567890123456789ll;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
template <typename T>
T GCD(T a, T b) {
  long long t;
  while (a) {
    t = a;
    a = b % a;
    b = t;
  }
  return b;
}
template <typename T>
string toString(T a) {
  return to_string(a);
}
template <typename T>
void toInt(string s, T& x) {
  stringstream str(s);
  str >> x;
}
inline int add(int x, int y) {
  x += y;
  if (x >= mod) x -= mod;
  return x;
}
inline int sub(int x, int y) {
  x -= y;
  if (x < 0) x += mod;
  return x;
}
inline int mul(int x, int y) { return (x * 1ll * y) % mod; }
inline int powr(int a, long long b) {
  int x = 1 % mod;
  while (b) {
    if (b & 1) x = mul(x, a);
    a = mul(a, a);
    b >>= 1;
  }
  return x;
}
inline int inv(int a) { return powr(a, mod - 2); }
const int N = 2e5 + 5;
int arr[N], mp[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, q;
  cin >> n >> q;
  set<int> s;
  vector<int> vec;
  int v;
  vec.push_back(0);
  for (int i = 1; i <= n; i++) {
    cin >> v;
    vec.push_back(v);
    s.insert(i);
    arr[v] = i;
    mp[v]++;
  }
  int ans = 0;
  vector<int> temp;
  for (int i = 1; i <= n; i++) {
    if (s.size() && *s.begin() != i) continue;
    v = vec[i];
    int last = arr[v];
    temp.clear();
    int sz = 0, mx = 0;
    for (auto it : s) {
      if (it > last) break;
      sz++;
      mx = max(mx, mp[vec[it]]);
      last = max(last, arr[vec[it]]);
      temp.push_back(it);
    }
    for (auto it : temp) {
      s.erase(it);
    }
    ans += (sz - mx);
  }
  cout << ans << '\n';
  return 0;
}
