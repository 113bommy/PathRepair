#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int N = 2e5 + 5, M = 2 * N + 5;
int n, k;
char s[N];
int check(int i, int j) {
  for (int f = 0; f < k; ++f) {
    int x = i + f;
    int y = j + f;
    if (s[x] > s[y] || y >= n)
      return 1;
    else if (s[x] < s[y])
      return -1;
  }
  return 0;
}
void printtt() {
  printf("%d\n", n);
  for (int i = 0; i < n; ++i) printf("%c", s[i % k]);
  exit(0);
}
string plusone(string s) {
  string ret;
  int len = s.size();
  int i = len - 1;
  while (i >= 0 && s[i] == '9') {
    --i;
    ret += "0";
  }
  if (i == -1)
    ret += "1";
  else {
    ++s[i];
    while (i >= 0) ret += s[i--];
  }
  reverse(ret.begin(), ret.end());
  return ret;
}
void plusone() {
  string tmp;
  for (int i = 0; i < k; ++i) tmp += s[i];
  tmp = plusone(tmp);
  printf("%d\n", n);
  for (int i = 0; i < n; ++i) printf("%c", tmp[i % k]);
  exit(0);
}
int main() {
  scanf("%d%d%s", &n, &k, s);
  for (int i = k; i < n; i += k) {
    int ret = check(0, i);
    if (ret == 1)
      printtt();
    else if (ret == -1)
      plusone();
  }
  printf("%d\n%s\n", n, s);
}
