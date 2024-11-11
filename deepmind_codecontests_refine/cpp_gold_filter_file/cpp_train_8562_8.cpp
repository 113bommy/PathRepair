#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-11;
const double Pi = acos(-1.0);
template <class T>
inline T countbit(T n) {
  return n ? 1 + countbit(n & (n - 1)) : 0;
}
template <class T>
inline T sqr(T a) {
  return a * a;
}
template <class T>
inline void checkmin(T &a, T b) {
  if (a == -1 || a > b) a = b;
}
template <class T>
inline void checkmax(T &a, T b) {
  if (a < b) a = b;
}
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int main() {
  string s;
  cin >> s;
  int ans = 1, now = 1;
  for (int i = 1; i < s.size(); i++) {
    if (s[i] != s[i - 1] || now == 5) {
      ans++;
      now = 1;
    } else
      now++;
  }
  cout << ans << endl;
  return 0;
}
