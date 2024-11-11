#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool chkmin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T>
inline bool chkmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
const int oo = 0x3f3f3f3f;
const int maxn = 100000;
char s[maxn + 5];
int main() {
  scanf("%s", s);
  int n = strlen(s);
  bool find = 0;
  for (int i = (0), i_end_ = (n); i < i_end_; ++i)
    if (s[i] != 'a') {
      find = 1;
      for (int j = i; j < n; ++j) {
        if (s[j] == 'a') break;
        --s[j];
      }
      break;
    }
  if (!find) ++s[n - 1];
  printf("%s\n", s);
  return 0;
}
