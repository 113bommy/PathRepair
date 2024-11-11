#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void Read(T &x) {
  char c = getchar();
  bool f = false;
  for (x = 0; !isdigit(c); c = getchar()) {
    if (c == '-') {
      f = true;
    }
  }
  for (; isdigit(c); c = getchar()) {
    x = x * 10 + c - '0';
  }
  if (f) {
    x = -x;
  }
}
template <typename T>
inline bool CheckMax(T &a, const T &b) {
  return a < b ? a = b, true : false;
}
template <typename T>
inline bool CheckMin(T &a, const T &b) {
  return a > b ? a = b, true : false;
}
const int N = 5005;
vector<int> p[N];
int n, ans, c[N];
char s[N];
int main() {
  scanf("%s", s), n = strlen(s);
  for (int i = 0; i < n; ++i) {
    p[s[i] - 'a'].push_back(i), s[i + n] = s[i];
  }
  for (int i = 0; i < 26; ++i) {
    int val = 0;
    for (int j = 0; j < n; ++j) {
      int ret = 0;
      for (int k = 0; k < 26; ++k) {
        c[k] = 0;
      }
      for (auto x : p[i]) {
        ++c[s[j + x] - 'a'];
      }
      for (int k = 0; k < 26; ++k) {
        if (c[k] == 1) {
          ++ret;
        }
      }
      CheckMax(val, ret);
    }
    ans += val;
  }
  printf("%lf\n", (double)ans / n);
  return 0;
}
