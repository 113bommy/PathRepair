#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
template <typename T, typename U>
inline void amin(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
inline void amax(T &x, U y) {
  if (x < y) x = y;
}
void err(istream_iterator<string> it) { cerr << '\n'; }
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  if (0 == 0) return;
  cerr << *it << " = " << a << " ";
  err(++it, args...);
}
long long A[1000];
int main() {
  ios ::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  string s, t = "";
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'a' || s[i] == 'b') t.push_back(s[i]);
  }
  int i = 0;
  while (i < t.length() && t[i] == 'b') i++;
  if (i == t.length()) {
    cout << 0 << '\n';
    return 0;
  }
  long long temp = 1;
  i++;
  long long ans = 1;
  while (i < t.length()) {
    if (t[i] == 'b') {
      ans = (ans * (temp + 1)) % 1000000007;
      temp = 0;
    } else
      temp++;
    i++;
  }
  ans = (ans * (temp + 1)) % 1000000007;
  ans--;
  cout << ans << '\n';
  return 0;
}
