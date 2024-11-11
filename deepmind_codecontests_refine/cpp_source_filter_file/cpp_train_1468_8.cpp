#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T bigmod(T p, T e, T M) {
  long long int ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % M;
    p = (p * p) % M;
  }
  return (T)ret;
}
template <class T>
inline T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T>
inline T modinverse(T a, T M) {
  return bigmod(a, M - 2, M);
}
string s;
void solve() {
  cin >> s;
  int i;
  for (i = 0; i < s.length() - 1; i++) {
    if (s[i] == 'a' || s[i] == 'u' || s[i] == 'o' || s[i] == 'i' ||
        s[i] == 'e' || s[i] == 'n')
      continue;
    if (s[i + 1] == 'a' || s[i + 1] == 'u' || s[i + 1] == 'o' ||
        s[i + 1] == 'i' || s[i + 1] == 'e')
      continue;
    cout << "NO";
    return;
  }
  if (s[i] == 'a' || s[i] == 'u' || s[i] == 'o' || s[i] == 'i' || s[i] == 'e' ||
      s[i] == 'n')
    cout << "YES";
  cout << "NO";
}
int main() {
  solve();
  return 0;
}
