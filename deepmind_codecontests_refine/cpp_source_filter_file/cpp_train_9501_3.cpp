#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool umax(T &x, T y) {
  return (y > x) ? x = y, true : false;
}
template <typename T>
void read(T &x) {
  cin >> x;
}
template <typename T, typename T0>
void read(T &x, T0 &y) {
  cin >> x >> y;
}
template <typename T, typename T0, typename T1>
void read(T &x, T0 &y, T1 &z) {
  cin >> x >> y >> z;
}
template <typename T, typename T0, typename T1, typename T2>
void read(T &x, T0 &y, T1 &z, T2 &w) {
  cin >> x >> y >> z >> w;
}
template <typename T>
void read(vector<T> &oneD, long long int n) {
  for (long long int i = 0; i < n; i++) {
    read(oneD[i]);
  }
}
template <typename T>
void read(T oneD[], long long int n) {
  for (long long int i = 0; i < n; i++) {
    read(oneD[i]);
  }
}
void sol() {
  long long int n, mi = 0, ans = 1000000007;
  read(n);
  string s, s1;
  read(s);
  s1 = s;
  for (int j = (0); ((1) > 0 ? j < (3) : j > (3)); j += (1)) {
    mi = 0;
    s = s1;
    for (int i = (0); ((1) > 0 ? i < (n) : i > (n)); i += (1)) {
      if (s[i] == 'R' && s[(i + 1) % n] == 'R' && s[(i - 1 + n) % n] == 'R') {
        if (s[(i + 2) % n] == 'L') {
          s[i] = 'L';
        } else
          s[i + 1] = 'L';
        mi++;
      }
      if (s[i] == 'L' && s[(i + 1) % n] == 'L' && s[(i - 1 + n) % n] == 'L') {
        if (s[(i + 2) % n] == 'R') {
          s[i] = 'R';
        } else
          s[i + 1] = 'R';
        mi++;
      }
    }
    ans = min(ans, mi);
    s1 = s1.substr(1) + s[0];
  }
  cout << ans;
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t = 1;
  read(t);
  for (int i = (0); ((1) > 0 ? i < (t) : i > (t)); i += (1)) {
    sol();
  }
}
