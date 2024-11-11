#include <bits/stdc++.h>
template <typename T>
inline void SWAP(T &a, T &b) {
  T tmp = a;
  a = b;
  b = tmp;
}
template <typename T>
inline T ABS(const T &val) {
  return val < 0 ? -val : val;
}
template <typename T>
inline T MAX(T a, T b) {
  return a > b ? a : b;
}
template <typename T>
inline T MIN(T a, T b) {
  return a < b ? a : b;
}
template <typename T>
inline T SQR(const T &a) {
  return a * a;
}
const int INTinf = 1000000000;
const int nINTinf = 0 - 2147483648;
const long long LLinf = 9223372036854775807LL;
using namespace std;
string s;
int main() {
  cin >> s;
  bool at = false;
  int ss = s.size();
  for (int i = 0;; i++) {
    if (i >= ss) break;
    if ((s.size() - i >= 3) && i) {
      if (s[i] == 'd' && s[i + 1] == 'o' && s[i + 2] == 't') {
        s = s.substr(0, i) + '.' + s.substr(i + 3);
        ss -= 2;
      }
    }
    if (!at) {
      if (s[i] == 'a' && s[i + 1] == 't') {
        s = s.substr(0, i) + '@' + s.substr(i + 2);
        ss--;
        at = true;
      }
    }
  }
  cout << s << endl;
  return 0;
}
