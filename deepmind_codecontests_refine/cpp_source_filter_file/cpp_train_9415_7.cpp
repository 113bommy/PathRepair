#include <bits/stdc++.h>
using namespace std;
template <class T>
T _abs(T n) {
  return (n < 0 ? -n : n);
}
template <class T>
T _max(T a, T b) {
  return (!(a < b) ? a : b);
}
template <class T>
T _min(T a, T b) {
  return (a < b ? a : b);
}
template <class T>
T sq(T x) {
  return x * x;
}
template <class T>
T gcd(T a, T b) {
  return (b != 0 ? gcd<T>(b, a % b) : a);
}
template <class T>
T lcm(T a, T b) {
  return (a / gcd<T>(a, b) * b);
}
template <class T>
bool inside(T a, T b, T c) {
  return a <= b && b <= c;
}
template <class T>
string toStr(const T &x) {
  stringstream s;
  s << x;
  return s.str();
}
template <class T>
int toInt(const T &x) {
  stringstream s;
  s << x;
  int r;
  s >> r;
  return r;
}
template <class T>
string itoa(T a) {
  if (!a) return "0";
  string ret;
  for (T i = a; i > 0; i = i / 10) ret.push_back((i % 10) + 48);
  reverse((ret).begin(), (ret).end());
  return ret;
}
string toBin(int n) {
  string s;
  for (int i = (int)10 - 1; i >= 0; --i) s += ((bool)(n & (1LL << (i))) + '0');
  return s;
}
int dr[] = {0, -1, 0, 1};
int dc[] = {1, 0, -1, 0};
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  int a, b, c, cr = 0;
  cin >> a >> b;
  for (int i = 1; i <= a; i++) {
    cin >> c;
    cr += c;
  }
  int n = (a - 1) * 10 + cr;
  if (n > b)
    cout << "-1";
  else
    cout << 2 * (n - 1) + (b - n) / 5 << endl;
  return 0;
}
