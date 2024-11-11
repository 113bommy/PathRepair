#include <bits/stdc++.h>
using namespace std;
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
int sz(T x) {
  return x.size();
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
  if (x >= 1000000007) x -= 1000000007;
  return x;
}
inline int sub(int x, int y) {
  x -= y;
  if (x < 0) x += 1000000007;
  return x;
}
inline int mul(int x, int y) { return (x * 1ll * y) % 1000000007; }
inline int powr(int a, long long b) {
  int x = 1 % 1000000007;
  while (b) {
    if (b & 1) x = mul(x, a);
    a = mul(a, a);
    b >>= 1;
  }
  return x;
}
inline int inv(int a) { return powr(a, 1000000007 - 2); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int x, y, z;
  cin >> x >> y >> z;
  if (z && (x + z) >= y && (y + z) >= x) {
    cout << "?" << '\n';
    return 0;
  }
  int a = x - y;
  if (a == 0)
    cout << 0 << '\n';
  else if (a < 0)
    cout << "-" << '\n';
  else
    cout << "+" << '\n';
  return 0;
}
