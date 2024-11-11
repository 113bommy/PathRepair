#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f;
const int N = 3e5 + 10;
const int M = 11;
const double PI = acos(-1.0);
bool debug = false;
char s[N << 1];
int main() {
  scanf("%s", s);
  int n = strlen(s), flag = 0;
  for (int i = 1; i < n; ++i)
    if (s[i] != s[0]) flag = 1;
  if (!flag)
    puts("Impossible");
  else {
    for (int i = 0; i < n; ++i) s[n + i] = s[i];
    for (int i = 1; i < n; ++i) {
      flag = 1;
      for (int j = 0; j < n / 2; ++j)
        if (s[i + j] != s[i + n - 1 - j]) flag = 0;
      if (flag) {
        for (int j = 0; j < n / 2; ++j)
          if (s[i + j] != s[j]) flag = 0;
        if (!flag) {
          puts("1");
          return 0;
        }
      }
    }
    puts("2");
  }
  return 0;
}
