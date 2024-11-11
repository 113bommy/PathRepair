#include <bits/stdc++.h>
using namespace std;
template <class F, class T>
T convert(F a, int p = -1) {
  stringstream ss;
  if (p >= 0) ss << fixed << setprecision(p);
  ss << a;
  T r;
  ss >> r;
  return r;
}
template <class T>
T gcd(T a, T b) {
  T r;
  while (b != 0) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
template <class T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
template <class T>
T sqr(T x) {
  return x * x;
}
template <class T>
T cube(T x) {
  return x * x * x;
}
template <class T>
int getbit(T s, int i) {
  return (s >> i) & 1;
}
template <class T>
T onbit(T s, int i) {
  return s | (T(1) << i);
}
template <class T>
T offbit(T s, int i) {
  return s & (~(T(1) << i));
}
template <class T>
int cntbit(T s) {
  return s == 0 ? 0 : cntbit(s >> 1) + (s & 1);
}
const long double PI = acos(-1.0);
const long double eps = 1e-9;
const int dr[] = {-1, 0, +1, 0};
const int dc[] = {0, +1, 0, -1};
const int inf = (int)1e9 + 5;
const long long linf = (long long)1e16 + 5;
const long long mod = (long long)1e9 + 7;
bool check(string s, char k) {
  bool track[300];
  memset(track, false, sizeof(track));
  for (int i = 0; i < (((int)(s).size())); ++i) {
    track[s[i]]++;
  }
  for (char i = '0'; i <= k; i++) {
    if (!track[i]) return false;
  }
  return true;
}
int main() {
  std::ios::sync_with_stdio(false);
  int n;
  while (cin >> n) {
    char k;
    cin >> k;
    int cnt = 0;
    while (n--) {
      string s;
      cin >> s;
      if (check(s, k)) cnt++;
    }
    cout << cnt << endl;
  }
}
