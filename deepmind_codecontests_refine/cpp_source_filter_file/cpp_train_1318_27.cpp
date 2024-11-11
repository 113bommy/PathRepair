#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T bigMod(T p, T e, T M) {
  long long ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % M;
    p = (p * p) % M;
  }
  return (T)ret;
}
template <class T>
inline T modInverse(T a, T M) {
  return bigMod(a, M - 2, M);
}
template <class T>
inline T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T>
inline T lcm(T a, T b) {
  a = abs(a);
  b = abs(b);
  return (a / gcd(a, b)) * b;
}
template <class T>
inline string int2String(T a) {
  ostringstream str;
  str << a;
  return str.str();
}
const int dr[] = {0, 1, 0, -1, -1, 1, 1, -1, -2, -2, 2, 2, -1, -1, 1, 1};
const int dc[] = {1, 0, -1, 0, 1, 1, -1, -1, -1, 1, -1, 1, -2, 2, -2, 2};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  string s;
  cin >> s;
  map<char, int> mp;
  for (auto c : s) mp[c]++;
  if (!mp['o'])
    cout << "NO" << endl;
  else
    cout << (mp['-'] % mp['o'] ? "NO" : "YES") << endl;
  return 0;
}
